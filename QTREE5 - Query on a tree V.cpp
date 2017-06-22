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
#define pil pair<int,lli>
#define pli pair<lli,int>
#define pll pair<lli,lli>
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
#define slf2(a,b) scanf("%lf %lf",&a,&b)
#define sf(n) scanf("%f",&n)
#define sllu(n) scanf("%llu",&n)
#define ss(n) scanf(" %s ",n)
#define sch(n) scanf(" %c ",&n)
#define PI 3.1415926535897932384626433832795028841971693993751

#define inchar          getchar_unlocked
#define outchar(x)      putchar_unlocked(x)


template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}


int n,m;
#define N 100100
#define LN 21

set<int> g[N];
int depth[N], p[N][LN], sub[N];
int par[N];
int ans[N];

void dfs0(int u,int pa)
{
	p[u][0] = pa;
	for(auto v : g[u])
	{
		if(v!=pa)
		{
			depth[v] = depth[u]+1;
			dfs0(v,u);
		}
	}
}

void pre()
{
	depth[1] = 0;
	dfs0(1,0);
	for(int j=1;j<LN;j++)
	{
		for(int i=1;i<=n;i++)
			p[i][j] = p[p[i][j-1]][j-1];
	}
}

int lca(int u,int v)
{
	if(depth[u]<depth[v])
		swap(u,v);
	int diff = depth[u]-depth[v];
	for(int i=0;i<LN;i++)
	{
		if(diff & (1<<i))
			u = p[u][i];
	}
	if(u==v)
		return u;
	for(int i=LN-1;i>=0;i--)
	{
		if(p[u][i]!=p[v][i])
		{
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

int dist(int u,int v)
{
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}

int nn;
void dfs1(int u,int p)
{
	sub[u] = 1;
	nn++;
	for(auto v : g[u])
	{
		if(v!=p)
		{
			dfs1(v,u);
			sub[u] += sub[v];
		}
	}
}

int get_centroid(int u,int p)
{
	for(auto v : g[u])
	{
		if(v!=p && sub[v]>(nn/2))
			return get_centroid(v,u);
	}
	return u;
}

void decompose(int root,int p)
{
	nn = 0;
	dfs1(root,root);
	int centroid = get_centroid(root,root);
	if(p==-1)
		p = centroid;
	par[centroid] = p;
	for(auto v : g[centroid])
	{
		g[v].erase(centroid);
		decompose(v,centroid);
	}
	g[centroid].clear();
}

bool white[N];

multiset<pair<int,int>> ss[N];

int solve(int x)
{
	multiset<pair<int,int>> &q = ss[x];

	while(!q.empty())
	{
		pair<int,int> cur = *q.begin();
		if(!white[cur.S])
			q.erase(q.begin());
		else
			return cur.F;
	}
	return 100000;
}

int main()
{
	inpos(n);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
       		inpos(u);
        	inpos(v);
		g[u].insert(v);
		g[v].insert(u);
	}
	memset(white,false,sizeof(white));
	pre();
	decompose(1,-1);

	int q;
    	inpos(q);
	while(q--)
	{
		int t,x;
        	inpos(t);
        	inpos(x);
		if(t==0)
		{
			white[x] = !white[x];
			if(white[x])
			{
				int cur = x;
				while(1)
				{
					ss[cur].insert(mp(dist(cur,x),x));
					if(cur==par[cur])
						break;
					cur = par[cur];
				}
			}
		}
		else
		{
			int ans = 100000,cur = x;
			while(1)
			{
				ans = min(ans,dist(x,cur)+solve(cur));
				if(cur==par[cur])
					break;
				cur = par[cur];
			}
			outpos(ans==100000 ? -1 : ans);
		}
	}
	return 0;
}
