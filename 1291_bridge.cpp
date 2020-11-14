/**
    Form a condensed graph with the bridges as edge
    The condensed graph will be a tree
    Answer is the half the number of leafs in this tree
    Consider these two trees:
    4 3     4 4
    0 1     0 1
    0 2     0 2
    0 3     0 3
            0 4
   ans:2   ans:2
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
const int MAX = 10000 + 2;

vector<int> G[MAX];
bool vis[MAX];
int T, N;
int st[MAX];
int low[MAX];
int dgr[MAX];
int idx[MAX];
set<pii> bridge;

inline void init()
{
    N = T = 0;
    memset(vis, false, sizeof vis);
    memset(dgr, 0, sizeof dgr);
    for(int i = 0; i < MAX; i++){
        G[i].clear();
    }
    bridge.clear();
}

void dfs(int u, int p)
{
    vis[u] = true;
    st[u] = ++T;
    low[u] = st[u];

    for(int v: G[u]){
        if(v == p) continue;
        if(vis[v]){
            low[u] = min(low[u], st[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > st[u]) // u-v is a bridge
                bridge.insert({min(u, v), max(u, v)});
        }
    }
}
void dfs2(int u)
{
    vis[u] = true;
    idx[u] = N;

    for(int v: G[u]){
        bool isBridge = (bridge.find({min(u, v), max(u, v)})!=bridge.end());
        if(vis[v] or isBridge) continue;
        dfs2(v);
    }
}

inline void solve()
{   
    init();

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(0, 0);
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ++N;
            dfs2(i);
        }
    }
    for(int u = 0; u < n; u++){
        for(int v: G[u]){
            bool isBridge = (bridge.find({min(u, v), max(u, v)})!=bridge.end());
            if(isBridge){
                dgr[idx[u]]++;
            }
        }
    }
    int leaf = 0;
    for(int i = 1; i <= N; i++)
        leaf += dgr[i]==1; 
    
    printf("%d\n", (int)ceil(leaf/2.0));
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