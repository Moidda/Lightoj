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

const int MAX = 1000 + 2;

int tot, sz;
bool vis[MAX];
int a[MAX];
vector<int> G[MAX];

inline void init()
{
    memset(vis, false, sizeof vis);
    for(int i = 0; i < MAX; i++)
        G[i].clear();
}

void dfs(int u)
{
    sz++;
    tot += a[u];
    vis[u] = true;
    for(int v: G[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

inline void solve()
{
    init();

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }

    bool ok = true;
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    if(sum%n) ok = false;
    sum /= n;

    for(int i = 1; i <= n and ok; i++){
        if(vis[i]) continue;
        tot = sz = 0;
        dfs(i);
        ok &= (tot%sz == 0 and tot/sz==sum);
    }
    printf("%s\n", (ok ? "Yes" : "No"));
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