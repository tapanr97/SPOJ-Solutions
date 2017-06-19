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

void in(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

vector<int> adj[10001];
int in_degree[10001];
int n,m;
vector<int> path;
set<int> ss;
int cnt = 0;

void bfs_topo()
{
	while(!ss.empty())
	{
		cnt++;
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
	in(n);
	in(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		in(u);
		in(v);
		adj[u].pb(v);
	    	in_degree[v]++;
	}

	for(int i=1;i<=n;i++)
	{
		if(!in_degree[i])
			ss.insert(i);
	}
	bfs_topo();
	if(cnt!=n)
	{
		printf("Sandro fails.");
		return 0;
	}
	for(int i=0;i<path.size();i++)
		printf("%d ",path[i]);
   	return 0;
}
