/**
    E(x) -> expected number of moves to such that x faces has already been seen
    From this state, either we can get a move and see an already seen face, or get a new face
        E(x) = (E(x)+1)*(x/n) + (E(x+1)+1)*(n-x)/n
    ->  E(x) = E(x+1) + n/n/x

    Answer is E(0), since we start with 0 faces seen
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

void solve()
{
    int n;
    scanf("%d", &n);
    double ans = 0;
    for(int i = 1; i <= n; i++)
        ans = ans + (1.0/i);

    printf("%.8f\n", ans*n);
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