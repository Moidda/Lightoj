/**
    Length of YES -> 3
    Length of NO -> 2

    There will be a total of n words, whose length will be s
    Let there be x YESs, and y NOs
            3*x + 2*y = s
            x + y = n 
    Solve this equation to find x,y

    Replace YES with 1, and NO with 0
    We have to place x 1s and y 0s and while forming such a string as "answer.txt"(explained in statement)
    we should calculate the number of mismatches occuring in the "output.txt"(explained in statement)

    The value of first position of "output.txt" will be 1.
    The value of all the other positions will be the value of the previous position in "answer.txt"

    So, the states for dp are #_of_yes_remaining, #_of_no_remaining, previous_value 
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

const int MAX = 5e3 + 2;

double dp[2][MAX][2];

/*
double E(int y, int n, int p)
{
    if(y==0 and n==0) return 0;
    if(vis[y][n][p]) return dp[y][n][p];
    vis[y][n][p] = true;
 
    double &ret = dp[y][n][p] = 0;
    if(y) ret += (E(y-1, n, 1) + (p!=1)) * ((double)y/(y+n));
    if(n) ret += (E(y, n-1, 0) + (p!=0)) * ((double)n/(y+n));
    return ret;
}
*/

inline void solve()
{
    int n, s;
    scanf("%d %d", &n, &s);
    int no = 3*n - s;
    int yes = s - 2*n;
    
    int now = 0, prv = 1;
    for(int ys_cnt = 0; ys_cnt <= yes; ys_cnt++){
        swap(now, prv);
        memset(dp[now], 0, sizeof dp[now]);
        
        for(int no_cnt = 0; no_cnt <= no; no_cnt++){
            for(int p = 0; p < 2; p++){
                double py = (double)ys_cnt/(ys_cnt + no_cnt);
                double pn = (double)no_cnt/(ys_cnt + no_cnt);
                
                if(ys_cnt) dp[now][no_cnt][p] += (dp[prv][no_cnt][1]   + (p!=1)) * py;
                if(no_cnt) dp[now][no_cnt][p] += (dp[now][no_cnt-1][0] + (p!=0)) * pn; 
            }
        }
    }

    double ans = 0;
    if(yes) ans +=  dp[prv][no][1] * ((double)yes/n);
    if(no)  ans += (dp[now][no-1][0]+1) * ((double)no/n);

    printf("%.8f\n", ans);
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