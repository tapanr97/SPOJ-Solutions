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

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,m;
		sii(n,m);
		char a[201][201];

		int dis[201][201];
		bool vis[201][201];
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sch(a[i][j]);
				vis[i][j] = false;
				dis[i][j] = 0;
			}
		}
		
		queue<pair<pair<int,int>,int>> q;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='1')
				{
					q.push(mp(mp(i,j),0));
					vis[i][j] = true;
				}
			}
		}

		
		while(!q.empty())
		{
			pair<int,int> p = q.front().F;
			int d = q.front().S;
			int x = p.F;
			int y = p.S;
			q.pop();
			vector<pair<int,int>> v;
			v.pb(mp(x-1,y));
			v.pb(mp(x,y-1));
			v.pb(mp(x+1,y));
			v.pb(mp(x,y+1));

			for(auto pp : v)
			{
				int xx = pp.F;
				int yy = pp.S;
				if(xx>=1 && xx<=n && yy>=1 && yy<=m)
				{
					if(!vis[xx][yy])
					{
					    dis[xx][yy] = d+1;
						q.push(mp(mp(xx,yy),d+1));
						vis[xx][yy] = true;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d ",dis[i][j]);
			printf("\n");
		}
		
	}
	return 0;
}
