#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
const int MAX = 50000 + 2;

char s[MAX];
int tr[MAX*50][4];
int isWord[MAX*50], dp[MAX*50];
int ans, N;

inline void init()
{
    memset(tr, -1, sizeof tr);
    memset(isWord, 0, sizeof isWord);
    memset(dp, 0, sizeof dp);
    ans = N = 0;
}

inline int f(char ch)
{
    if(ch == 'A') return 0;
    if(ch == 'T') return 1;
    if(ch == 'C') return 2;
    if(ch == 'G') return 3;
    return -1;
}

void Insert()
{
    int n = strlen(s);
    int now = 0;
    for(int i = 0; i < n; i++){
        if(tr[now][f(s[i])] == -1)
            tr[now][f(s[i])] = ++N;

        now = tr[now][f(s[i])];
    }
    isWord[now]++;
}

void dfs(int u, int dep)
{
    dp[u] = isWord[u];
    for(int i = 0; i < 4; i++){
        int v = tr[u][i];
        if(v != -1){
            dfs(v, dep+1);
            dp[u] += dp[v];
        }
    }
    ans = max(ans, dep*dp[u]);
}

inline void solve()
{
    init();

    int n;
    scanf("%d ", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        Insert();
    }
    dfs(0, 0);
    printf("%d\n", ans);
}

int32_t main()
{
    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }

    return 0;
}
