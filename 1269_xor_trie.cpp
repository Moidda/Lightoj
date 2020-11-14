/**
    Finding max pair xor with trie
*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise " << __LINE__ << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 23;
const ll INFL = 2e18 + 23;

const int MAX = 5e4 + 3;
const int MAX_NODE = MAX*32;

int N;
int tr[MAX_NODE][2];

void Insert(int x)
{
    int now = 0;
    for(int i = 30; i>=0; i--){
        int nxt = 0;
        if(x & (1<<i)) nxt = 1;
        if(tr[now][nxt] == -1) tr[now][nxt] = ++N;
        now = tr[now][nxt];
    }
}
int max_query(int x)
{
    int ret = 0;
    int now = 0;
    for(int i = 30; i>=0; i--){
        int xi = 0;
        if(x & (1<<i)) xi = 1;

        if(tr[now][xi^1] != -1){
            ret |= (1<<i);
            now = tr[now][xi^1];
        }
        else{
            now = tr[now][xi];
        }
    }
    return ret;
}
int min_query(int x)
{
    int ret = 0;
    int now = 0;
    for(int i = 30; i>=0; i--){
        int xi = 0;
        if(x & (1<<i)) xi = 1;
        if(tr[now][xi] != -1){
            now = tr[now][xi];
        }
        else{
            ret |= (1<<i);
            now = tr[now][xi^1];
        }
    }   
    return ret;
}

inline void solve()
{
    N = 0;
    memset(tr, -1, sizeof tr);

    int pref = 0;
    int mx = 0;
    int mn = INT_MAX;
    int n;
    scanf("%d", &n);
    
    Insert(0);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        pref = (pref^x);
        mx = max(mx, max_query(pref));
        mn = min(mn, min_query(pref));
        Insert(pref);
    }
    printf("%d %d\n", mx, mn);
}

int32_t main()
{
    FASTIO;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}