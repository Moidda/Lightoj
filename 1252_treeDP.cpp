/**
    Let's root the tree at node 1
    dp(u, i) -> minimum # of connected components for subtree u
                such that the maximum allowable cost is i

    While calculating dp(u, i), we either connect a child v of u to 
    u or don't connect it with u.

    If we consider connecting current child v with u that has edge cost w, then
        dp(u, i) -> dp(u, i-w-j) + dp(v, j) - 1;    for j=0 to min(k, i-w)

    If we dont connect current child v with u, then,
        dp(u, i) -> dp(u, i) + dp(v, j)             for j=0 to k

    Suppose there are two child, v1,v2 of u
    We calculated dp(u, i) for v1
    Now, while filling the dp table for v2, we need to use the dp table calculated 
    previously for v1, as we have seen from the two recursive relations above.
    (i.e. dp(u, i) depends on dp(u, i-w-j) )

    So, the dp table calculated for v1 has to be undisturbed while calculating
    the dp table for v2. So, I maintained two tables.

    However, using two tables is not necessary if the values for i is calculated
    from backwords for dp(u, i)
    i.e
        for(int i = k; i>=0; i--){...}
    insted of
        for(int i = 0; i<=k; i++){...}

    In this ways, the values of the "previous" iteration of dp remains undisturbed
    since the values that are being used to currently update, have not yet been updated.

    For example, we have just filled up the dp table for child v1 of u.
    Now, while filling the dp table for child v2 of u, let's say..
        dp(u, 7) and we're accessing dp(u, 4)
    this dp(u, 4) actually contains the value from when we calculated for v1, not v2.

    Code for memory optimized solution:
    https://rebornplusplus.github.io/codir/lo-1252-maintaining-communities.html
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

const int MAX = 100 + 2;

int n, k;
int dp[MAX][MAX];
int f[2][MAX];
vector<pii> G[MAX]; 

void init()
{
    for(int i = 0; i < MAX; i++)
        G[i].clear();
}

void dfs(int u, int p)
{
    bool is_leaf = true;
    for(pii ob: G[u]){
        int v = ob.XX;
        int w = ob.YY;
        if(v == p) continue;   
        dfs(v, u);
        is_leaf = false;
    }
    if(is_leaf){
        for(int i = 0; i <= k; i++)
            dp[u][i] = 1;

        return;
    }

    int now = 0;
    int prv = 1;
    bool base_case = true;
    
    for(pii ob: G[u]){
        int v = ob.XX;
        int w = ob.YY;
        if(v == p) continue;

        for(int i = 0; i <= k; i++)
            f[now][i] = INF;

        if(base_case){
            for(int i = 0; i <= k; i++){
                if(i-w>=0) f[now][i] = min(f[now][i], dp[v][i-w]);
                for(int j = 0; j <= k; j++)
                    f[now][i] = min(f[now][i], dp[v][j] + 1);
            }
            base_case = false;
        }
        else{
            for(int i = 0; i <= k; i++){
                for(int j = 0; j <= k; j++){
                    f[now][i] = min(f[now][i], f[prv][i] + dp[v][j]);
                    if(i-w-j>=0) f[now][i] = min(f[now][i], f[prv][i-w-j] + dp[v][j] - 1);
                }
            }
        }
        swap(now, prv);
    }

    for(int i = 0; i <= k; i++)
        dp[u][i] = f[prv][i];
}

inline void solve()
{
    init();

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].PB({v, w});
        G[v].PB({u, w});
    }
    dfs(1, 1);
    int ans = dp[1][k];
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