/**
    Let x be the first minimum amount of crackers for which mailbox explodes

    re(n, L, R) -> minimum # of crackers needed with n remaining mailboxes
                   such that it is assumed L<=x<=R
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

const int MAX = 100 + 2;

int dp[MAX][MAX][MAX];

inline int f(int L, int R)
{
    if(R<L) return 0;
    int len = R-L+1;
    return L*len + (len*(len-1))/2;
}

int re(int n, int L, int R)
{
    int &ret = dp[n][L][R];
    if(ret != -1)   return ret;
    if(L>R)         return ret = 0;
    if(n == 1)      return ret = f(L, R);

    ret = INF;
    for(int i = L; i <= R; i++)
        ret = min(ret, i + max(re(n-1, L, i-1), re(n, i+1, R)));

    return ret;
}

inline void solve()
{
    int k, n;
    scanf("%d %d", &n, &k);
    printf("%d\n", re(n, 1, k));
}

int32_t main()
{
    memset(dp, -1, sizeof dp);

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}