#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define F            first
#define S            second
#define pb(x)        push_back(x)
#define mp(a,b)      make_pair(a,b)
#define mt(a,b,c)    make_tuple(a,b,c)
#define sz           size()
#define all(A)       A.begin(), A.end()
#define mem(a, b)    memset(a, b, sizeof(a))   // all elements of A are b=0 or b=-1 else don't work
#define f0(i,b)      for(ll i=0;i<(b);i++)
#define f1(i,b)      for(ll i=1;i<=(b);i++)
#define f2(i,a,b)    for(ll i=(a);i<=(b);i++)
#define f3(i,b,a)    for(ll i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(ll i=(a);i!=(b);i+=(c))

#define mod          10000007
#define PI           acos(-1.0)
#define MAX3(a,b,c)  max(a,max(b,c))

/*------------------------Bitmask-------------------------------*/
#define bitOn(N,pos)      (N | (1LL<<(pos)))
#define bitOff(N,pos)     (N & (~(1LL<<(pos))))
#define bitCheck(N,pos)   ((bool)(N & (1LL<<(pos))))
#define bitFlip(a,k)      (a^(1LL<<(k)))

#define whilee(i,t)  while(i!=t)
#define  sl(a)       scanf("%lld",&a)
#define  pl(a)       printf("%lld\n",a)

//x = 1e18 means 10^18
//for(auto it =A.begin(); it!=A.end(); it++)
//sort(A.begin(),A.end()); //sort(A, +n, greater<int>());
//binary_search(A.begin(),A.end(),x);
//reverse(A.begin(), A.end());
//cout << *max_element(A.begin(), A.end());
//cout << *min_element(A.begin(), A.end());
//count(A.begin(), A.end(), X); //counts the occurrences of X
//distance(A.begin(),A.end());  //distance between first to last element
//accumulate(A.begin(), A.end(), 0); //add
//next_permutation(A.begin(), A.end());
//prev_permutation(A.begin(), A.end());
//swap(S[0], T[0]);

//scanf("%lld",&x);
//printf("%lld\n",x);
//printf("%I64d\n", a);
//while (scanf("%lld %lld", &a, &b) == 2)
//printf("Case %lld: %lld\n", t++, a);

/*----------------------- Graph Moves---------------------------*/
// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};  // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction // Kings Move
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1};  // Knight Direction
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1};  // Hexagonal Direction

//vector <ll> A;
//deque <ll> A;
//queue <ll> A;
//stack <ll> A;
//list <int> A;
//set <ll> A;
//map <ll,ll> A;
//unordered_map <ll, ll> A;
//pair <ll,ll> A ;
//tuple <ll, ll, ll> A;
//vector <pair <ll,ll>> A;
//bitset<32> bset1;
//bool ok = true;
//char ch;


int j=0, k=0, a, b, c, e, f, g, h, l, m, o, q, r, s, t=1, w, x, y, z, maxx=INT_MIN, minn=INT_MAX, ans=0, sum=0, flag=0, cnt=0;

vector<int> G[1005];// adjacency list of graph

vector<int> d, low;

int timer;

bool isArticulationPoint[1005];


int dfs(int u, int p)
{
    d[u] = low[u] = ++timer;
    int children=0;
    for(int i=0; i<(int)G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == p)
        {
            continue;
        }
        if(d[v])
        {
            low[u] = min(low[u], d[v]);
        }
        else
        {
            ++children;
            dfs(v, u);
            if(d[u] <= low[v])
            {
                isArticulationPoint[u] = 1;
            }
            low[u] = min(low[u], low[v]);
        }
    }
    return children;
}

void find_AP(int n)
{
    timer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            isArticulationPoint[i] = (dfs (i,i) > 1? 1 : 0);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);//NULL
    cout.tie(nullptr);//NULL
    int u, v, n;
    while (cin>>n && n!= 0)
    {
        cin.ignore();
        string S;
        mem(isArticulationPoint, 0);
        d.assign(n+5, 0);
        low.assign(n+5, 0);
        while (getline(cin, S) && S != "0")
        {
            stringstream X(S);
            X >> u;
            while(X >> v)
            {
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        find_AP(n);
        cnt=0;
        for(int i = 1; i<=n; i++)
        {
            if (isArticulationPoint[i])
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
        for(int i = 1; i<=n; i++)
        {
            G[i].clear();
        }
    }
    return 0;
}

