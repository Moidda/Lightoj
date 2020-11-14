/**
    Each element of the array appears k*n^(k-1) times in sum
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

int modexp(int a, int p, int mod)
{
    if(p == 0) return 1%mod;
    int ret = modexp(a, p/2, mod);
    ret = (1LL*ret*ret)%mod;
    if(p%2==1) ret = (1LL*ret*a)%mod;
    return ret;
}

inline void solve()
{
    int ans = 0;
    int n, k, mod;
    scanf("%d %d %d", &n, &k, &mod);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        x %= mod;
        ans += x;
        ans %= mod;
    }

    int x = (1LL*modexp(n, k-1, mod)*(k%mod)) % mod;
    ans = (x*ans) % mod;
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