//============================================================================
// Name        : abc++.cpp
// Author      : Tapan Modi
// Institute   : DA-IICT
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
#define LOCAL 0
#define li long int
#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pllilli pair<lli,lli>
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define slf(n) scanf("%lf",&n)
#define sf(n) scanf("%f",&n)
#define sllu(n) scanf("%llu",&n)
#define ss(n) scanf(" %s ",n)
#define PI 3.1415926535897932384626433832795028841971693993751
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);

const long double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;

int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}
void fastExecute(){ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli power(lli _a,lli _b){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}
lli gcd(lli a,lli b){if(b==0)return a;return gcd(b,a%b);}
lli lcm(lli a,lli b){return (a*b)/gcd(a,b);}
lli invmod(lli a,lli m){return powermod(a,m-2,m);}
lli r_d, r_x, r_y;
void extendedEuclid(lli r_A, lli r_B) {
    if(r_B == 0){r_d = r_A;r_x = 1;r_y = 0;}
    else{extendedEuclid(r_B, r_A%r_B);lli r_temp = r_x;r_x = r_y;r_y = r_temp - (r_A/r_B)*r_y;}
}
lli modInverse(lli r_A, lli r_M){extendedEuclid(r_A,r_M); return (r_x%r_M+r_M)%r_M;}

int in_degree[10001];
int n,m;
vector<int> path;
set<int> ss;
int cnt = 0;

void bfs_topo(vector<int> adj[])
{
	while(!ss.empty())
	{
		int u = *ss.begin();
		ss.erase(ss.begin());
		path.pb(u);
		vector<int> temp;
		for(int i=0;i<adj[u].size();i++)
		{
			in_degree[adj[u][i]]--;
			if(!in_degree[adj[u][i]])
				ss.insert(adj[u][i]);
		}
	}
}



int main()
{
	int t;
    cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
	    memset(in_degree,0,sizeof(in_degree));
	    vector<int> adj[10001];
		int tot=1;
		map<string,int> name;
		map<int,string> ver;
		
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int u,v;
		    string uu,vv;
		    cin>>uu>>vv;
			if(!name.count(uu))
			{
				name[uu] = tot;
				ver[tot] = uu;
				u = tot;
				tot++;
			}
			else
			    u = name[uu];
			if(!name.count(vv))
			{
				name[vv] = tot;
				ver[tot] = vv;
				v = tot;
				tot++;
			}
			else
			    v = name[vv];
			adj[u].pb(v);
			in_degree[v]++;
		}

		for(int i=1;i<=n;i++)
		{
			if(!in_degree[i])
				ss.insert(i);
		}
		bfs_topo(adj);
		printf("Scenario #%d:\n",ii);
		for(int i=0;i<path.size();i++)
			cout<<ver[path[i]]<<endl;
		printf("\n");
		path.clear();
	}
    return 0;
}
