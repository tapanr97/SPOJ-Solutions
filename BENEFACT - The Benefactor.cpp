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

bool vis[50001];
lli dis[50001];
int n;
map<pair<int,int>,lli> edges;
int bfs(int s,vector<int> g[])
{
	vis[s] = true;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v : g[u])
		{
			if(!vis[v])
			{
				vis[v] = true;
				q.push(v);
				dis[v] = max(dis[v],dis[u]+edges[mp(u,v)]);
			}
		}
	}
	lli mx=0;
	int ind=0;
	for(int i=1;i<=n;i++)
	{
		if(mx<dis[i])
		{
			mx = dis[i];
			ind = i;
		}
	}
	return ind;
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		memset(dis,0,sizeof(dis));
		si(n);
		vector<int> g[50001];
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			lli w;
			sii(u,v);
			slli(w);
			g[u].pb(v);
			g[v].pb(u);
			edges[mp(u,v)] = w;
			edges[mp(v,u)] = w;
		}
		int v1 = bfs(1,g);
		memset(vis,false,sizeof(vis));
		memset(dis,0,sizeof(dis));
		int v2 = bfs(v1,g);
		printf("%lld\n",dis[v2]);
	}
	return 0;
}
