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
#define sii(n,m) scanf("%d %d",&n,&m)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define slli2(a,b) scanf("%lld %lld",&a,&b)
#define slli3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define slf(n) scanf("%lf",&n)
#define sf(n) scanf("%f",&n)
#define sllu(n) scanf("%llu",&n)
#define ss(n) scanf(" %s ",n)
#define sch(n) scanf(" %c ",&n)
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
void print(vector<int> &v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<"\n";}
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

int w,h;
int dis[26][26];
bool vis[26][26];
void dijkstra(int si,int sj,char a[][26])
{
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			dis[i][j] = INF;
			vis[i][j] = false;
		}
	}
	dis[si][sj] = 0;
	multiset<pair<int,pair<int,int>>> ss;
	ss.insert(mp(0,mp(si,sj)));
	while(!ss.empty())
	{
	    pair<int,pair<int,int>> tmp = *ss.begin();
		pair<int,int> p = tmp.S;
		int x = p.F;
		int y = p.S;
		ss.erase(ss.begin());
		if(vis[x][y])
			continue;
		vis[x][y] = true;
		vector<pair<int,int>> v;
		v.pb(mp(x-1,y));
		v.pb(mp(x,y-1));
		v.pb(mp(x+1,y));
		v.pb(mp(x,y+1));
		for(auto pp : v)
		{
			int xx = pp.F;
			int yy = pp.S;
			if(xx>=1 && xx<=h && yy>=1 && yy<=w)
			{
				if(a[xx][yy]!='X')
				{
					int w;
					if(a[xx][yy]!='D')
    					w = a[xx][yy]-'0';
    				else
    				    w = 0;
					if(dis[xx][yy]>dis[x][y]+w)
					{
						dis[xx][yy] = dis[x][y]+w;
						ss.insert(mp(dis[xx][yy],mp(xx,yy)));
					}
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		sii(w,h);
		if(w==0 && h==0)
			break;
		char a[26][26];
		int si,sj,di,dj;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				sch(a[i][j]);
				if(a[i][j]=='S')
				{
					si = i;
					sj = j;
				}
				else if(a[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
			}
		}
		dijkstra(si,sj,a);
		printf("%d\n",dis[di][dj]);
	}
	return 0;
}
