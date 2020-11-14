/**
    Let,
        N = x + (x+1) + (x+2) + (x+3) + ... + (x+L-1)
    ->  N = L*x + (L*(L-1))/2
    ->  N - (L*(L-1))/2 = L*x
    ->  N/L - (L-1)/2 = x
    x is integer.
    Let:
    Case 1) L is odd:
            L-1 is even
            (L-1)/2 is integer
            Implying N/L should be an integer.
            Thus, L is an odd factor of N

    Case 2) L is even:
            L-1 is odd. (L-1)/2 is X.5
            So N/L should be Y.5
            Since N is an integer, the only case where N/L can be of the form Y.5 is when L=2
            So N has to be odd

    Conclusion:
        if N is even, case 2 doesnt occur, answer is no of odd factors of N
        if N is odd, both case occurs. Answer is no of odd factors of N except N itself 
        (since L cannot be equal to N) and an extra 1 for case 2 (where L=2)
        So taking N itself as a factor and avoiding adding an extra 1 would result in
        the same answer

        Answer is number of odd factors of N
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

#define MAX 10010896
#define LMT 3164
#define i64 long long

int flag[MAX >> 6], primes[800000], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve()
{
    int i, j, k;
    for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j=i*i, k=i<<1; j < MAX; j+=k) isc(j);
    primes[0] = 2, total = 1;
    for(i = 3; i < MAX; i+=2) if(!ifc(i)) primes[total++] = i;
}

void solve()
{
    ll n;
    scanf("%lld", &n);
    while(n%2 == 0) 
        n >>= 1LL;

    ll ans = 1;
    for(int i = 1; i<total and primes[i]*primes[i] <= n; i++){
        if(n%primes[i] == 0){
            int cnt = 0;
            while(n%primes[i] == 0){
                n /= primes[i];
                cnt++;
            }
            ans = ans*(cnt+1);
        }
    }
    if(n>1)
        ans = ans*2LL;

    printf("%lld\n", ans-1);
}

int32_t main()
{
    sieve();

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d: ", nc);
        solve();
    }

    return 0;
}