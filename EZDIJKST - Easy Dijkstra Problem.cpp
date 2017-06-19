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
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define slli2(a,b) scanf("%lld %lld",&a,&b);
#define slli3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);
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

bool vis[10001];
int dis[10001];
int n,m;

void dijkstra(int s,vector<pair<int,int>> adj[])
{
	for(int i=0;i<10001;i++)
	{
		vis[i] = false;
		dis[i] = INF;
	}
	multiset<pair<int,int>> ss;
	dis[s] = 0;
	ss.insert(mp(0,s));
	while(!ss.empty())
	{
		pair<int,int> p = *ss.begin();
		ss.erase(ss.begin());
		int u = p.S;
		if(vis[u])
			continue;
		vis[u] = true;
		for(auto pp : adj[u])
		{
			int v = pp.S;
			int w = pp.F;
			if(dis[v]>dis[u]+w)
			{
				dis[v] = dis[u]+w;
				ss.insert(mp(dis[v],v));
			}
		}
	}
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		vector<pair<int,int>> adj[10001];
		sii(n,m);
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			siii(u,v,w);
			adj[u].pb(mp(w,v));
		}
		int a,b;
		sii(a,b);
		dijkstra(a,adj);
		if(dis[b]<INF)
			printf("%d\n",dis[b]);
		else
			printf("NO\n");
	}
	return 0;
}
