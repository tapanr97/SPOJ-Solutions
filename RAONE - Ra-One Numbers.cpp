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

void get_dig(lli a,vector<int> &aa)
{
	while(a)
	{
		aa.pb(a%10);
		a/=10;
	}
}

lli dp[19][170][170][2];

lli solve(int ind,int es,int os,int tight,vector<int> a)
{
	if(ind==-1)
	{
	    	if(es<=os)
	            return 0;
	    	else if((es-os)==1)
		    return 1;
		else
		    return 0;
	}
    	if(dp[ind][es][os][tight]!=-1)
        	return dp[ind][es][os][tight];
	lli ans = 0;
	int lim = (tight==1) ? a[ind] : 9;
	for(int i=0;i<=lim;i++)
	{
	    if(ind%2==0)
    		ans += solve(ind-1,es,os+i,(tight==1 && i==a[ind]) ? 1 : 0,a);
    	    else
    		ans += solve(ind-1,es+i,os,(tight==1 && i==a[ind]) ? 1 : 0,a);    	
	}
	return dp[ind][es][os][tight] = ans;
}
		

int main()
{
    	int t;
    	inpos(t);
	while(t--)
	{
		lli a,b;
		inpos(a);
		inpos(b);
		if(a==-1 && b==-1)
			break;
		a--;
		vector<int> aa,bb;
		get_dig(a,aa);
		get_dig(b,bb);
		for(int i=0;i<19;i++)
			for(int j=0;j<170;j++)
				for(int k=0;k<170;k++)
				    for(int l=0;l<2;l++)
    					dp[i][j][k][l] = -1;

		lli t1 = solve(aa.size()-1,0,0,1,aa);
		for(int i=0;i<19;i++)
			for(int j=0;j<170;j++)
				for(int k=0;k<170;k++)
				    for(int l=0;l<2;l++)
    					dp[i][j][k][l] = -1;
		if(a<=0)
		    t1 = 0;
		lli t2 = solve(bb.size()-1,0,0,1,bb);
		outpos(t2-t1);
	}
	return 0;
}
