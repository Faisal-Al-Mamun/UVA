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
#define MIN5(a,b,c,d,e)  min(a,min(b,min(c,min(d,e))))

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

// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};  // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1};  // 8 Direction
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
//string S, T, U;

ll ManhattanDis(ll a,  ll b, ll x, ll y)
{
    return abs(a-x) + abs(b-y);
}

ll i=0, j=0, k=0, a, b, c, d, e, f, g, h, l, m, n, o, p, q, r, s, t=1, u, v, w, x, y, z, maxx=INT_MIN, minn=INT_MAX, ans=0, sum=0, flag=0, cnt=0;
ll A, B, C, D, E, row, col;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);//NULL
    cout.tie(nullptr);//NULL

    cin>>t;
    while(t--)
    {
        ll X[5][5];
        f0(i,5)
        {
            f0(j,5)
            {
                X[i][j]=0;
            }
        }
        cin>>n;
        f0(i,n)
        {
            cin>>x>>y>>m;
            X[x][y]=m;
        }
        ll R[5];
        ans = INT_MAX;
        for(a=0; a<25; a++)
        {
            for(b=a+1; b<25; b++)
            {
                for(c=b+1; c<25; c++)
                {
                    for(d=c+1; d<25; d++)
                    {
                        for(e=d+1; e<25; e++)
                        {
                            sum =0;
                            f0(row,5)
                            {
                                f0(col,5)
                                {
                                    A = ManhattanDis(row, col, a/5, a%5) * X[row][col];
                                    B = ManhattanDis(row, col, b/5, b%5) * X[row][col];
                                    C = ManhattanDis(row, col, c/5, c%5) * X[row][col];
                                    D = ManhattanDis(row, col, d/5, d%5) * X[row][col];
                                    E = ManhattanDis(row, col, e/5, e%5) * X[row][col];
                                    sum+=MIN5(A,B,C,D,E);
                                }
                            }
                            if(sum<ans)
                            {
                                ans=sum;

                                R[0]=a;
                                R[1]=b;
                                R[2]=c;
                                R[3]=d;
                                R[4]=e;
                            }
                        }
                    }
                }
            }
        }
        cout<<R[0]<<" "<<R[1]<<" "<<R[2]<<" "<<R[3]<<" "<<R[4]<<endl;
    }
    return 0;
}
