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

const int MAX = 100 + 2;

int c[MAX];
vector<pii> G[MAX];
int dis[MAX][MAX]; /// dis[u][f] -> min cost to reach u with f fuel remaining in tank

inline void init()
{
    for(int i = 0; i < MAX; i++)
        G[i].clear();
}

int dijkstra(int s, int t, int tank)
{
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            dis[i][j] = INF;

    priority_queue<pair<pii, int>> pq;
    dis[s][0] = 0;
    pq.push(MP(MP(-1*dis[s][0], -1*0), s));

    while(!pq.empty()){
        int u = pq.top().YY;
        int W = -1*pq.top().XX.XX;
        int F = -1*pq.top().XX.YY;
        pq.pop();

        if(dis[u][F] < W) continue;

        for(pii ob: G[u]){
            int v = ob.XX;
            int w = ob.YY;
            if(F>=w and dis[v][F-w] > dis[u][F]){
                dis[v][F-w] = dis[u][F];
                pq.push(MP(MP(-1*dis[v][F-w], -1*(F-w)), v));
            }
            if(F+1 <= tank and dis[u][F+1] > dis[u][F] + c[u]){
                dis[u][F+1] = dis[u][F] + c[u];
                pq.push(MP(MP(-1*dis[u][F+1], -1*(F+1)), u));
            }
        }
    }

    int ret = INF;
    for(int i = 0; i <= tank; i++)
        ret = min(ret, dis[t][i]);

    return ret;
}

inline void solve()
{
    init();

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].PB({v, w});
        G[v].PB({u, w});
    }

    int q;
    scanf("%d", &q);
    while(q--){
        int cap, s, t;
        scanf("%d %d %d", &cap, &s, &t);
        int ans = dijkstra(s, t, cap);
        if(ans == INF) puts("impossible");
        else printf("%d\n", ans);
    }
}

int32_t main()
{
    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d:\n", nc);
        solve();
    }

    return 0;
}

