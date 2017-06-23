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
//lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
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

lli base[2] = {1571,31069};
lli mod[2] = {1085814053, 1796153501};

bool prime[200];

void sieve(){
	for(int i=0;i<200;i++){
//		lp[i] = i;
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	for(int i=2;i<sqrt(200);i++){
		if(prime[i]){
			for(int j=2*i;j<200;j+=i){
				prime[j] = false;
//				lp[j] = min(lp[j],(lli)i);
			}
		}
	}
}

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
	    else if(prime[es-os])
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
    	si(t);
    	sieve();
	while(t--)
	{
		lli a,b;
		slli2(a,b);
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
		printf("%lld\n",t2-t1);
	}
	return 0;
}
