/*
a1, b1, 0, 0, 0, c1     f(n-1)      f(n)
1,  0,  0, 0, 0,  0     f(n-2)      f(n-1)
0,  1,  0, 0, 0,  0     f(n-3)      f(n-2)
0,  0, c2, a2, b2, 0    g(n-1)  =   g(n)
0,  0, 0,  1, 0,  0     g(n-2)      g(n-1)
0,  0, 0,  0,  1, 0     g(n-3)      g(n-2)
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

int MOD;

#define DIM 6 // Set value according to problem.
struct matrix{
  int a[DIM][DIM];
    // constructor. Make an empty array.
    matrix() {
        memset(a, 0, sizeof(int) * DIM * DIM);
    }
    // constant matrix (M). Set value according to problem.
    void unit_matrix(int a1, int b1, int c1, int a2, int b2, int c2) {
        a[0][0] = a1;   a[0][1] = b1;   a[0][2] = 0;    a[0][3] = 0;    a[0][4] = 0;    a[0][5] = c1;
        a[1][0] = 1;    a[1][1] = 0;    a[1][2] = 0;    a[1][3] = 0;    a[1][4] = 0;    a[1][5] = 0;
        a[2][0] = 0;    a[2][1] = 1;    a[2][2] = 0;    a[2][3] = 0;    a[2][4] = 0;    a[2][5] = 0;
        a[3][0] = 0;    a[3][1] = 0;    a[3][2] = c2;   a[3][3] = a2;   a[3][4] = b2;   a[3][5] = 0;
        a[4][0] = 0;    a[4][1] = 0;    a[4][2] = 0;    a[4][3] = 1;    a[4][4] = 0;    a[4][5] = 0;
        a[5][0] = 0;    a[5][1] = 0;    a[5][2] = 0;    a[5][3] = 0;    a[5][4] = 1;    a[5][5] = 0;
    }
 
    void print() {
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
 
    matrix operator* (matrix b) {
        matrix c;
        for (int k = 0; k < DIM; ++ k) {
            for (int i = 0; i < DIM; ++i) {
                for (int j = 0; j < DIM; ++j) {
                    // c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]);
                    c.a[i][j] = (c.a[i][j] + 1LL*a[i][k]*b.a[k][j]) % MOD;
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

inline void solve()
{   
    
}

int32_t main()
{
    // FASTIO;

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        printf("Case %d:\n", nc);
        solve();
    }    

    return 0;
}