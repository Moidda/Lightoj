/**
    2^1 + 2^2 + 2^3 + ... + 2^12 <= 2^13 = 8192
    There are less than 8192 lucky numbers
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

ll lmt = 1000000000000;

vector<ll> lucky;
set<ll> st;

void re1(ll cur)
{
    if(cur > lmt) return;
    if(cur) lucky.PB(cur);
    re1(cur*10 + 4);
    re1(cur*10 + 7);
}

void re2(int idx, ll cur)
{
    if(idx >= lucky.size()) return;

    for(int i = idx; i < lucky.size(); i++){
        ll nxt = cur*lucky[i];
        if(nxt > lmt or nxt <= 0) return;
        st.insert(nxt);
        re2(i, nxt);
    }
}

inline void solve()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);
    int ans = upper_bound(lucky.begin(), lucky.end(), b) - lower_bound(lucky.begin(), lucky.end(), a);
    printf("%d\n", ans);
}

int32_t main()
{
    re1(0);
    sort(lucky.begin(), lucky.end());
    re2(0, 1);
    for(ll x: st)
        lucky.PB(x);

    sort(lucky.begin(), lucky.end());
    lucky.erase(unique(lucky.begin(), lucky.end()), lucky.end());

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}