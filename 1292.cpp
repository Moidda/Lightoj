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

inline pii slope(pii p1, pii p2)
{
    int y = p1.YY - p2.YY;
    int x = p1.XX - p2.XX;
    if(x<0 and y>0) x *= -1, y *= -1;
    if(x<0 and y<0) x *= -1, y *= -1;
    if(x == 0) return MP(0, 0);
    if(y == 0) return MP(0, 1);
    int g = __gcd(abs(x), abs(y));
    y /= g;
    x /= g;
    return MP(y, x);
}

inline void solve()
{
    int n;
    scanf("%d", &n);
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i].XX, &a[i].YY);

    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<pii> vec;
        for(int j = i+1; j < n; j++)
            vec.PB(slope(a[i], a[j]));
    
        sort(vec.begin(), vec.end());
        int cnt = 0;
        for(int j = 0; j < vec.size(); ){
            int k = j;
            while(k<vec.size() and vec[k]==vec[j]) k++;
            cnt = max(cnt, k-j);
            j = k;
        }
        ans = max(ans, cnt);
    }
    
    printf("%d\n", ans+1);
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