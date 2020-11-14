/**
    V = (L-2x)(W-2x)x
    V = (LW - 2x(L+W) + 4x^2)x
    V = LWx - 2x^2(L+W) + 4x^3
    
    dV/dx = LW - 4x(L+W) + 12x^2 = 0
        ->  a = 12
        ->  b = -4(L+W)
        ->  c = LW
        x = (-b +- sqrt(b^2 - 4ac)) / 2a

    But lets do a ternary search.
    The graph of the function V clearly shows 
    ternary search should be possible
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

const double EPS = 1e-9;

inline double volume(double L, double W, double x)
{
    return (L-2*x)*(W-2*x)*x;
}

inline void solve()
{
    double L, W;
    scanf("%lf %lf", &L, &W);
/*
// Calculus got me AC

    double a = 12;
    double b = -4*(L+W);
    double c = L*W;
    double x = (-b - sqrt(b*b-4*a*c)) / (2*a);
    double V = (L-2*x)*(W-2*x)*x;
*/

    double lo = 0, hi = min(L/2, W/2);
    double V = 0;
    while(hi-lo > EPS){
        double m1 = lo + (hi-lo)/3;
        double m2 = hi - (hi-lo)/3;
        double v1 = volume(L, W, m1);
        double v2 = volume(L, W, m2);
        if(v1 > v2) hi = m2;
        else lo = m1;
    }

    printf("%.8f\n", max(volume(L, W, lo), volume(L, W, hi)));
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