#include <bits/stdc++.h>
using namespace std;

#define INF             1e9
#define INFL            1e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cout << endl;
#define HOISE           cerr << "hoise" << endl
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << endl
#define READ            freopen("alu.txt", "r", stdin)
#define WRITE           freopen("vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

#define MASK(x)         for(int i = 4; i>=0; i--){ if(x&(1<<i))cout<<1;else cout<<0;  } cout << endl;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;

ll F[MAX];
ll inv[MAX];
ll invF[MAX];

inline int mult(ll x, ll y)
{
    return ((x%MOD)*(y%MOD)) % MOD;
}

int main()
{
//    READ;
//    WRITE;
    FASTIO;

    inv[0] = inv[1] = 1;
    for (ll i = 2; i < MAX; i++)
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;

    F[0] = 1;
    for(ll i = 1; i < MAX; i++)
        F[i] = (i*F[i-1])%MOD;

    invF[0] = invF[1] = 1;
    for(int i = 2; i < MAX; i++)
        invF[i] = (inv[i]*invF[i-1]) % MOD;

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        int n;
        cin >> n;
        vector<int> a(n), cum(n, 0);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        cum[0] = a[0];
        for(int i = 1; i < n; i++)
            cum[i] = cum[i-1] + a[i];

        vector<ll> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            int x = a[i]-1;
            int y = cum[i-1];
            dp[i] = mult(dp[i-1], F[x+y]);
            dp[i] = mult(dp[i], invF[x]);
            dp[i] = mult(dp[i], invF[y]);
        }
        cout << "Case " << nc << ": " << dp[n-1] << "\n";
    }

    return 0;
}

