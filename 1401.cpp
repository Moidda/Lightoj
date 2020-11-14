/**
    Game Theory, Grundy Number
    Consider each interval/gap of ... as nim pile
**/


#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define INF             1e9
#define INFL            1e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise" << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define READ            freopen("alu.txt", "r", stdin)
#define WRITE           freopen("vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pff;

const int MAX = 100 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e6 + 2;
const int MOD = 998244353;
const double PY = acos(-1.0);
const double EPS = 1E-9;

int dp[MAX][3][3];

/**
    lft=0 -> no condition
    lft=1 -> O needed at lft
    lft=2 -> X needed at lft

    Same for right
**/
int grundy(int len, int lft, int rt)
{
    if(len == 0) return 0;
    if(len == 1){
        if(lft==rt or lft==0 or rt==0) return 1;
        return 0;
    }

    int &ret = dp[len][lft][rt];
    if(ret != -1) return ret;

    set<int> st;

    for(int i = 1; i <= len; i++){
        if(i == 1){
            if(lft == 0 or lft == 1) st.insert(grundy(len-1, 2, rt));
            if(lft == 0 or lft == 2) st.insert(grundy(len-1, 1, rt));
        }
        else if(i == len){
            if(rt == 0 or rt == 1) st.insert(grundy(len-1, lft, 2));
            if(rt == 0 or rt == 2) st.insert(grundy(len-1, lft, 1));
        }
        else{
            int nxt1 = (grundy(i-1, lft, 2)^grundy(len-i, 2, rt));
            int nxt2 = (grundy(i-1, lft, 1)^grundy(len-i, 1, rt));
            st.insert(nxt1);
            st.insert(nxt2);
        }
    }

    int mex = 0;
    while(st.find(mex) != st.end()) mex++;
    return ret = mex;
}

void solve(int nc)
{
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for(int i = 0; i < n; ){
        if(s[i]!='.'){
            i++;
            continue;
        }

        int j = i;
        while(j<n and s[j]=='.') j++;

        int len = j-i;
        int lft = 0, rt = 0;
        if(i-1>=0 and s[i-1]=='O') lft = 2;
        if(i-1>=0 and s[i-1]=='X') lft = 1;
        if(j<n and s[j]=='O') rt = 2;
        if(j<n and s[j]=='X') rt = 1;

        ans = (ans^grundy(len, lft, rt));
        i = j;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (s[i]!='.');

    cout << "Case " << nc << ": ";
    if(cnt%2 == 0){
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
    else{
        if(ans) cout << "No\n";
        else cout << "Yes\n";
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif

//    FASTIO;

    memset(dp, -1, sizeof dp);

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        solve(nc);
    }

    return 0;
}
