#include <bits/stdc++.h>
using namespace std;

#define INF             501
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

const int MAX = 1000 + 5;

int dis[MAX];
int spf[MAX];

inline void init()
{
    memset(dis, -1, sizeof dis);
}

inline void sieve()
{
    for(int i = 0; i < MAX; i++)
        spf[i] = i;
    for(int i = 2; i < MAX; i++)
        if(spf[i] == i)
            for(int j = i+i; j < MAX; j+=i)
                if(spf[j] == j)
                    spf[j] = i;
}

int bfs(int s, int t)
{
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;

    while(!Q.empty()){
        int u = Q.front();
//        DEBUG(u);
        Q.pop();
        if(u == t)
            return dis[u];

//        if(spf[u] == u)
//            continue;
//
//        int x = u;
//        while(x>1){
//            int y = spf[x];
//            if(dis[u+y] == -1){
//                dis[u+y] = dis[u]+1;
//                Q.push(u+y);
//            }
//            while(x%y==0)
//                x /= y;
//        }
        for(int i = 2; i*i <= u; i++){
            if(u%i == 0 and dis[u+i] == -1){
                dis[u+i] = dis[u]+1;
                Q.push(u+i);
            }
        }
    }
    return -1;
}

int main()
{
    READ;
    WRITE;
//    FASTIO;

    sieve();

    int tc;
    scanf("%d", &tc);
    for(int nc = 1; nc <= tc; nc++){
        init();
        int s, t;
        scanf("%d %d", &s, &t);
        int ans = bfs(s, t);
        printf("Case %d: %d\n", nc, ans);
    }

    return 0;
}
