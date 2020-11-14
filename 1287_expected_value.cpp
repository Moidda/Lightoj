/**
    E(m, u) -> represent the expected time when thief is at node u, with m as the mask
               of visited nodes

    Now, let from u, there are 2 "Eleceted junctions" as per statement, v1 and v2
    So,
    E(m, u) = (E(m|(1<<v1), v1) + edge_cost(u, v1)) * probability_of_going_to_v1
              +
              (E(m|(1<<v2), v2) + edge_cost(u, v2)) * probability_of_going_to_v2
              +
              (E(n, u) + 5) * probability_of_staying_at_u

    => 3*E(m, u) = (E(m|(1<<v1), v1) + edge_cost(u, v1)) + (E(m|(1<<v2), v2) + edge_cost(u, v2)) + (E(n, u) + 5)
    => 2*E(m, u) = SUM( E(m|(1<<v)) + edge_cost(u, v) ) + 5
    => E(m, u) = SUM( E(m|(1<<v)) + edge_cost(u, v) + 5 ) / no_of_EJ_of_u

    Last eqn can be calculated in dfs style
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
#define OFF(mask, i)    (!(mask & (1<<i)))
#define ON(mask, i)     (mask & (1<<i))

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 23;
const ll INFL = 2e18 + 23;

const int MAX = 15 + 1;

int n, m;
int G[MAX][MAX];
double dp[1<<15][MAX];
int vis[1<<15][MAX];

inline void init()
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            G[i][j] = INF;

    memset(vis, -1, sizeof vis);
}

bool dfs(int mask, int u)
{
    if(vis[mask][u] != -1)
        return vis[mask][u];

    if(mask == (1<<n)-1){
        dp[mask][u] = 0;
        return vis[mask][u] = 1;
    }

    int ej = 0;
    dp[mask][u] = 5;
    for(int v = 0; v < n; v++){
        if(G[u][v]!=INF and OFF(mask, v) and dfs(mask|(1<<v), v)){
            ej++;
            dp[mask][u] += dp[mask|(1<<v)][v] + G[u][v];
        }
    }
    if(ej == 0){
        dp[mask][u] = 0;
        return vis[mask][u] = 0;
    }
    else{
        dp[mask][u] = dp[mask][u]/ej;
        return vis[mask][u] = 1;
    }
}

inline void solve()
{
    init();

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;
    }
    dfs(1, 0);
    printf("%.8f\n", dp[1][0]);
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