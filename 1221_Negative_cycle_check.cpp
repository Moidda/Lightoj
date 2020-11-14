/**
    SUM(I)/SUM(E) > P
    => SUM(I) > P*SUM(E)
    => P*SUM(E) - SUM(I) < 0
    Assigne edge weight to P*E - I and check for existance of -ve cycle
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

int G[MAX][MAX];
int dis[MAX][MAX];

inline void solve()
{
    int n, R, P;
    scanf("%d %d %d", &n, &R, &P);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            G[i][j] = INF;

    for(int i = 0; i < R; i++){
        int u, v, I, E;
        scanf("%d %d %d %d", &u, &v, &I, &E);
        G[u][v] = P*E-I;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = G[i][j];

    for(int w = 0; w < n; w++)
        for(int u = 0; u < n; u++)
            for(int v = 0; v < n; v++)
                dis[u][v] = min(dis[u][v], min(dis[u][w]+dis[w][v], INF));

    bool ok = false;
    for(int i = 0; i < n; i++)
        ok |= (dis[i][i] < 0);

    if(ok) puts("YES");
    else puts("NO");
}

int32_t main()
{
    // FASTIO;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}