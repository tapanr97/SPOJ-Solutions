//============================================================================
// Name        : abc++.cpp
// Author      : Tapan Modi
// Version     :
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
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define sllu(n) scanf("%llu",&n)
#define ss(n) scanf("%s",n)
#define PI 3.14159265359

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
void fastExecute(){	ios_base::sync_with_stdio(false);}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n;
		si(n);
		string st[10005];
		vector<pair<int,int>> v[10005];
		map<string,int> mymap;
		for(int i=1;i<=n;i++)
		{
			cin>>st[i];
			mymap.insert(mp(st[i],i));
			int m;
			si(m);
			for(int j=0;j<m;j++)
			{
				int x,w;
				si(x);
				si(w);
				v[i].pb(mp(x,w));
			}
		}

		int q;
		si(q);
		while(q--)
		{
			string s1,s2;
			cin>>s1>>s2;
			map<string,int> :: iterator it = mymap.find(s1);
			int ue = it->second;
			it = mymap.find(s2);
			int ve = it->second;
            
			int dis[10005];
			bool vis[10005];
		    	for(int j=0;j<10005;j++)
		    	{
				dis[j]=INF;
				vis[j]=false;
		    	}
			dis[ue] = 0;
			multiset<pair<int,int>> s;
			s.insert(mp(0,ue));
			while(!s.empty())
			{
				pair<int,int> p = *s.begin();
				s.erase(p);

				int x = p.second;
				int w = p.first;
				if(vis[x])
					continue;
				vis[x] = true;
				for(int j=0;j<v[x].size();j++)
				{
					int xe = v[x][j].first;
					int we = v[x][j].second;
					if(dis[xe]>dis[x]+we)
					{
						dis[xe] = dis[x]+we;
						s.insert(mp(dis[xe],xe));
					}
				}
			}

			printf("%d\n",dis[ve]);
		}
	}
    return 0;
}
