/*
    Game theory, Grundy value
    Pattern Finding
*/

#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define INF             1e9
#define INFL            1e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise" << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define READ            freopen("alu.txt", "r", stdin)
#define WRITE           freopen("vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pff;

const int MAX = 2e5 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e6 + 2;
const int MOD = 998244353;
const double PY = acos(-1.0);
const double EPS = 1E-9;

//int dp[MAX];
//
//int grundy(int n)
//{
//    if(n == 1) return 0;
//    if(dp[n] != -1) return dp[n];
//
//    set<int> st;
//    int upto = n/2;
//    for(int i = 1; i <= upto; i++)
//        st.insert(grundy(n-i));
//
//    int mex = 0;
//    while(st.find(mex) != st.end()) mex++;
//    return dp[n] = mex;
//}

//void brute()
//{
//    memset(dp, -1, sizeof dp);

//    cout << grundy(2) << "\n";

//    for(int i = 1; i <= 500; i+=2){
//        cout << i << ": " << grundy(i) << "\n";
//        if(i%2 == 0) assert(grundy(i) == i/2);
//    }
//}

int32_t main()
{
#ifndef ONLINE_JUDGE
//    READ;
//    WRITE;
#endif

//    FASTIO;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            while(x%2 == 1) x >>= 1;
            x /= 2;
            ans = (ans^x);
        }

        printf("Case %d: ", nc);

        if(ans) puts("Alice");
        else puts("Bob");
    }

    return 0;
}

