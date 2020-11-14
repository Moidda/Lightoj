/**
    Every nodes are reachable from every other nodes in SCC
    Find the SCC and create a condensed graph, which will be a DAG
    Answer is the maximum of number of nodes with zero indegree and number of nodes with zero outdegree
*/

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
const int MAX = 20000 + 2;

vector<int> G[MAX], GT[MAX];
stack<int> stk;
bool vis[MAX];
bool in[MAX], out[MAX];
int idx[MAX];
int N;

inline void Clear(int n)
{
    for(int i = 0; i <= n; i++){
        G[i].clear();
        GT[i].clear();
    }
    memset(idx, 0, sizeof idx);
    memset(in, false, sizeof in);
    memset(out, false, sizeof out);
    N = 0;
}

void dfs1(int u)
{
    vis[u] = true;
    for(int v: G[u])
        if(!vis[v])
            dfs1(v);

    stk.push(u);
}
void dfs2(int u)
{
    vis[u] = true;
    idx[u] = N;
    for(int v: GT[u])
        if(!vis[v])
            dfs2(v);
}

void scc(int n)
{
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs1(i);

    memset(vis, false, sizeof vis);
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        if(!vis[u]){
            ++N;
            dfs2(u);
        }
    }
}

inline void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].PB(v);
        GT[v].PB(u);
    }

    scc(n);

    if(N == 1){
        printf("0\n");
        Clear(n);
        return;
    }

    for(int u = 1; u <= n; u++)
        for(int v: G[u])
            if(idx[u] != idx[v]){
                out[idx[u]] = true;
                in[idx[v]] = true;
            }

    int sink = 0, source = 0;
    for(int i = 1; i <= N; i++){
        sink += (out[i]==0);
        source += (in[i]==0);
    }
    printf("%d\n", max(sink, source));

    Clear(n);
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