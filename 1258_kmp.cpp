/*
lightoj 1258:
anncb aaababaaa ..... -> s
..... aaababaaa bcnna -> reverse of s
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

const int MAX = 3e6 + 3;

char s[MAX];
int n;

vector<int> prefix_function() {
    vector<int> pi(2*n+1);
    for (int i = 1; i < 2*n+1; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

inline void solve()
{
    scanf("%s", s);
    n = strlen(s);
    
// s = reverse of s + "#" + s
    s[n] = '#';
    for(int i = n+1, j = 0; i < 2*n+1; i++, j++) s[i] = s[j];
    for(int i = 0, j = n-1; i<j; i++, j--) swap(s[i], s[j]);
/////////////////////////////

    vector<int> pi = prefix_function();
    int ans = 2*n-pi[2*n];
    printf("%d\n", ans);
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

