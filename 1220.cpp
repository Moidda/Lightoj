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

const int MAX_VALUE = 1e5 + 4;

bool composite[MAX_VALUE];
vector<int> prime;

void sieve()
{
    composite[0] = composite[1] = true;
    for(int i = 2; i < MAX_VALUE; i++){
        if(!composite[i]){
            prime.PB(i);
            for(int j = i+i; j < MAX_VALUE; j+=i)
                composite[j] = true;
        }
    }    
}

inline void solve()
{
    bool isneg = false;
    int g = 0;
    ll x;
    scanf("%lld", &x);
    
    if(x<0){
        isneg = true;
        x = abs(x);
    }

    for(int i = 0; 1LL*prime[i]*prime[i] <= x; i++){
        if(x%prime[i]) continue;
        int cnt = 0;
        while(x%prime[i] == 0){
            cnt++;
            x /= prime[i];
        }
        g = __gcd(g, cnt);
    }
    if(x>1) g = 1;

    if(isneg){
        int temp = 1;
        for(int i = 1; i*i <= g; i++){
            if(g%i == 0){
                int j = g/i;
                if(i%2) temp = max(temp, i);
                if(j%2) temp = max(temp, j);
            }
        }
        g = temp;
    }
    printf("%d\n", g);
}

int32_t main()
{
    // FASTIO;

    sieve();

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }    

    return 0;
}