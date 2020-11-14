/**
    dp(m, i, j) -> # of arrangements with m set of people (mask)
                   such that the person i stands at the end of the queue
                   and a total of j people are dissatisfied
                   
                   Since j people are dissatisfied, the total dissatisfaction index
                   will be j*k

    Precalculate dp to answer queries in constant time.
    Trivial case is when k=0, then every arrangements will be valid and the answer
    will be n!
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

const int MAX = 12 + 2;

int n, k, q;
bool G[MAX][MAX];
ll dp[(1<<12) + 2][MAX][MAX];
ll F[MAX];

inline void solve()
{
    memset(G, false, sizeof G);

    scanf("%d %d %d", &n, &k, &q);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        while(x--){
            int v;
            scanf("%d", &v);
            v--;
            G[i][v] = true;
        }
    }

    memset(dp, 0, sizeof dp);
    for(int m = 0; m < (1<<n); m++){
        int popcount = __builtin_popcount(m);
        if(popcount == 1){
            for(int i = 0; i < n; i++)
                if(ON(m, i))
                    dp[m][i][0] = 1;
        }
        else{
            for(int i = 0; i < n; i++){
                if(ON(m, i)){
                    int prvmask = (m^(1<<i));
                    
                    for(int j = 0; j < popcount; j++)
                        for(int x = 0; x < n; x++)
                            if(ON(prvmask, x) and j - G[i][x] >= 0)
                                dp[m][i][j] += dp[prvmask][x][j - G[i][x]];
                }
            }
        }
    }

    vector<ll> v(n+1, 0);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
        v[i] += dp[(1<<n)-1][j][i];

    while(q--){
        int r;
        scanf("%d", &r);
        if(k == 0){
            printf("%lld\n", F[n]);
            continue;
        }
        int x = r/k;
        ll ans = 0;
        for(int i = 0; i <= min(x, n-1); i++)
            ans += v[i];
    
        printf("%lld\n", ans);
    }
}

int32_t main()
{
    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i < MAX; i++)
        F[i] = F[i-1]*i;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d:\n", nc);
        solve();
    }    

    return 0;
}