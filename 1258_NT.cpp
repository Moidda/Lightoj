/**
    n^k = A.BC*(10^m) ----> m = floor(log10(n^k)) = floor(k*log10(n))
=>  k*log10(n) = log10(A.BC) + m
=>  log10(A.BC) = k*log10(n) - floor(k*log10(n))
=>  A.BC = 10^(k*log10(n) - floor(k*log10(n)))
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

#define int long long

int modexp(int a, int p, int mod)
{
    if(p == 0) return 1%mod;
    int ret = modexp(a, p/2, mod);
    ret = (ret*ret)%mod;
    if(p%2==1) ret = (ret*a)%mod;
    return ret;
}

void solve()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    int q = modexp(n, k, 1000);
    double x = k*log10(n) - floor(k*log10(n));
    double p = pow(10.0, x)*100.0;

    printf("%.3lld %.3lld\n", (int)p, q);
}

main()
{
    // FASTIO;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }
}