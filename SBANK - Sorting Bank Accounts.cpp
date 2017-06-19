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
		vector<string> v;
		map<string,int> mymap;
		int n;
    		scanf(" %d ",&n);
		for(int i=0;i<n;i++)
		{
			char st[33];
			cin.getline(st,33);
			auto it = mymap.find(st);
			if(it==mymap.end())
			{
				v.pb(st);
				mymap.insert(mp(st,1));
			}
			else
			{
				int f = it->second;
				f++;
				mymap.erase(st);
				mymap.insert(mp(st,f));
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			auto it = mymap.find(v[i]);
			cout<<v[i]<<" "<<it->second<<endl;
		}
		cout<<endl;
	}
    	return 0;
}
