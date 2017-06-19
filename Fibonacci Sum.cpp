#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ull unsigned long long int
ull powerFast(ull n)
{
	ull res[2][2] = {{1,0},{0,1}};
	ull a[2][2] = {{1,1},{1,0}};
	while(n)
	{
		if(n&1)
		{
			ull x = (res[0][0]*a[0][0]+res[0][1]*a[1][0])%MOD;
			ull y = (res[0][0]*a[0][1]+res[0][1]*a[1][1])%MOD;
			ull z = (res[1][0]*a[0][0]+res[1][1]*a[1][0])%MOD;
			ull w = (res[1][0]*a[0][1]+res[1][1]*a[1][1])%MOD;
			res[0][0] = x;
			res[0][1] = y;
			res[1][0] = z;
			res[1][1] = w;
		}
		ull x = (a[0][0]*a[0][0]+a[0][1]*a[1][0])%MOD;
		ull y = (a[0][0]*a[0][1]+a[0][1]*a[1][1])%MOD;
		ull z = (a[1][0]*a[0][0]+a[1][1]*a[1][0])%MOD;
		ull w = (a[1][0]*a[0][1]+a[1][1]*a[1][1])%MOD;
		a[0][0] = x;
		a[0][1] = y;
		a[1][0] = z;
		a[1][1] = w;
		n>>=1;
	}
	return (res[0][1]);
}

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ull n,m;
	 	cin>>n>>m;
        cout<<(powerFast(m+2) - powerFast(n+1) + MOD)%MOD<<endl;
	}
	return 0;
}
