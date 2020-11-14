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

const int MAX = 100 + 3;
const int MOD = 1e9 + 7;

int n1, n2, n3;
int dp[MAX][MAX][MAX][2];
char s1[MAX], s2[MAX], s3[MAX];
int nxt1[MAX][26];
int nxt2[MAX][26];

int re(int i, int j, int k, int idx)
{
    if(k == n3) return 1;
    int &ret = dp[i][j][k][idx];
    if(ret != -1) return ret;

    ret = 0;
    if(idx==0 and i<n1){      /// take from s1
        if(s1[i] == s3[k]){
                            ret = (ret + re(i+1, j, k+1, 0)) % MOD;
            if(k+1 < n3)    ret = (ret + re(i+1, j, k+1, 1)) % MOD;
        }
        ret = (ret + re(i+1, j, k, 0)) % MOD;
    }
    else if(idx==1 and j<n2){ /// take from s2
        if(s2[j] == s3[k]){
                            ret = (ret + re(i, j+1, k+1, 0)) % MOD;
            if(k+1 < n3)    ret = (ret + re(i, j+1, k+1, 1)) % MOD;
        }
        ret = (ret + re(i, j+1, k, 1)) % MOD;
    }
    return ret;
}

inline void solve()
{
    memset(dp, -1, sizeof dp);

    scanf("%s %s %s", s1, s2, s3);
    n1 = strlen(s1);
    n2 = strlen(s2);
    n3 = strlen(s3);
    printf("%d\n", (re(0, 0, 0, 0) + re(0, 0, 0, 1)) % MOD);
}

int32_t main()
{
    // FASTIO;

    int tc;
    scanf("%d ", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}