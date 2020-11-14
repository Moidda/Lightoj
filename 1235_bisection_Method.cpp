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

const int MAX = 20;

int a[MAX];

void re(int i, int n, int sum, vector<int> &vec)
{
    if(i == n){
        vec.PB(sum);
        return;
    }
    re(i+1, n, sum, vec);
    re(i+1, n, sum+a[i], vec);
    re(i+1, n, sum+a[i]+a[i], vec);
}

inline void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    vector<int> v1, v2;
    re(0, n/2, 0, v1);
    re(n/2, n, 0, v2);
    sort(v2.begin(), v2.end());

    bool ok = false;
    for(int x: v1){
        if(x > k) continue;
        int y = k-x;
        int j = lower_bound(v2.begin(), v2.end(), y) - v2.begin();
        if(j<v2.size() and v2[j] == y)
            ok = true;
    }

    printf("%s\n", (ok ? "Yes":"No"));
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