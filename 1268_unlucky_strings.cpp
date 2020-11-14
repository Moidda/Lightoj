/**
    Lets consider the following dp state:
    dp(n, x) -> # of strings of length n, which has x length prefix of S as its suffix
    For a string to be lucky string, it should follow that 0 <= x < S.size

    After appending a character c at the end of this dp state, what will the next dp state be?
    Let,    
            Sx = x length prefix of S + c
            y  = length of longest prefix of S which is a suffix of Sx

    So the next dp state due to appending character c at the end will be
            dp(n+1, y)

    So we get,
            dp(n, x) = SUMOF( dp(n+1, y) )
                for each valid y we get due to appending any character

    Now the key observation here is that, the length of the string, i.e. n does not change anything
    All we need is the transition from x to y due to appending of some character c.
    So lets redefine our state:
            dp(i) -> # of ways we can get i-length prefix of S due to appending some character
                     at the end

    If S = "abba", an example of each state would be,
            dp(0) -> any string ending with : "...b"
            dp(1) -> any string ending with : "...a"
            dp(2) -> ans string ending with : "..ab"
    ans so on.
    Its clear that dp(n) is not a desirable state.
    So all the valid states are from 0...n-1


    Now, since the only thing that matters is how the suffix changes due to appending a character in the
    end, lets create a transition matrix M, where
            M[x][y] -> # of ways we can obtain y-length prefix of S, from x-length prefix of S

    Lets clear things with an example.
            S = "ab", the available characters are 'a', 'b'
            M = 
                 0 1
                ----
             0 | 1 1
             1 | 0 1


    Again, what does M represent?
    M represents the transition matrix due to adding ONE character at the end.
    Since we need to form a string of length n, we need to add n characters at the end.
    The transition matrix for that would simply be M^n
    The sum of row 0 of M^n would then be the answer, since we initially start from state 0
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

int N;

#define DIM 52 // Set value according to problem.
struct matrix{
  unsigned a[DIM][DIM];
    // constructor. Make an empty array.
    matrix() {
        memset(a, 0, sizeof(unsigned) * DIM * DIM);
    }
 
    void print() {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
 
    matrix operator* (matrix b) {
        matrix c;
        for (int k = 0; k < N; ++ k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]);
                    // c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};
matrix pow_matrix(matrix a, ll n) {
    if (n == 1) return a;
    matrix b = pow_matrix(a, n / 2);
    b = b * b;
    if (n & 1) b = b * a;
    return b;
}

/// KMP
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
/// maximum suffix of s1 which is a prefix of s2
int maxSuffixPrefix(string &s1, string &s2)
{
    string s = s2 + "#" + s1;
    vector<int> pi = prefix_function(s);
    return pi.back();
}

inline void solve()
{
    int n;
    string alpha, s;
    cin >> n;
    cin >> alpha >> s;

    matrix M;

    for(int pref = 0; pref < s.size(); pref++){
        for(char ch: alpha){
            string temp = s.substr(0, pref) + ch;
            M.a[pref][maxSuffixPrefix(temp, s)]++;
        }
    }

    N = s.size();
    M = pow_matrix(M, n);
    
    unsigned ans = 0;
    for(int i = 0; i < s.size(); i++)
        ans += M.a[0][i];

    cout << ans << "\n";
}

int32_t main()
{
    // FASTIO;

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        cout << "Case " << nc << ": ";
        solve();
    }

    return 0;
}