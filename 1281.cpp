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

const int MAX = 20000 + 2;

struct node{
    int u, w1, w2;
    node(){}
    node(int x, int y, int z)
    {
        u = x;
        w1 = y;
        w2 = z;
    }
};

bool operator <(const node &ob1, const node &ob2)
{
    if(ob1.w1 != ob1.w2) return ob1.w1 > ob2.w1;
    return ob1.w2 > ob2.w2;
}

int n, m, k, d;
vector<pii> G[MAX], H[MAX];
int dis[MAX][12];

inline void init()
{
    for(int i = 0; i < MAX; i++){
        G[i].clear();
        H[i].clear();
    }
}

void bfs(int s)
{
    for(int i = 0; i < MAX; i++) for(int j = 0; j <= 10; j++)
        dis[i][j] = INF;

    priority_queue<node> Q;
    dis[s][0] = 0;
    Q.push(node(0, 0, 0));

    while(!Q.empty()){
        node now = Q.top();
        Q.pop();
    
        if(dis[now.u][now.w2] < now.w1) continue;

        for(pii ob: G[now.u]){
            int v = ob.XX;
            int w = ob.YY;
            if(now.w1 + w < dis[v][now.w2]){
                dis[v][now.w2] = now.w1 + w;
                Q.push(node(v, dis[v][now.w2], now.w2));
            }
        }
        for(pii ob: H[now.u]){
            int v = ob.XX;
            int w = ob.YY;
            if(now.w2+1 > d) continue;
            if(now.w1 + w < dis[v][now.w2+1]){
                dis[v][now.w2+1] = dis[now.u][now.w2] + w;
                Q.push(node(v, dis[v][now.w2+1], now.w2+1));
            }
        }
    }
}

inline void solve()
{
    init();

    scanf("%d %d %d %d", &n, &m, &k, &d);
    for(int i = 0, u, v, w; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        G[u].PB({v, w});
    }
    for(int i = 0, u, v, w; i < k; i++){
        scanf("%d %d %d", &u, &v, &w);
        H[u].PB({v, w});
    }

    bfs(0);

    int ans = INF;
    for(int i = 0; i <= d; i++)
        ans = min(ans, dis[n-1][i]);

    if(ans == INF) puts("Impossible");
    else printf("%d\n", ans);
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