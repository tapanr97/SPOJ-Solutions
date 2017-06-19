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
#define plii pair<lli,lli>
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

int tree[400001];
void update(int l,int r,int idx,int node,int u)
{
    if(l>r || l>idx || r<idx)
        return;
    if(l==r && l==idx)
    {
        if(tree[node]>u)
            return;
        else if(tree[node]==u)
            return;
        else
            tree[node] = u;
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,idx,2*node,u);
    update(mid+1,r,idx,2*node+1,u);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
int query(int s,int e,int l,int r,int node)
{
    if(s>e || s>r || e<l)
        return 0;
    if(l<=s && r>=e)
        return tree[node];
    int mid = (s+e)/2;
    int a = query(s,mid,l,r,2*node);
    int b = query(mid+1,e,l,r,2*node+1);
    int res = max(a,b);
    return res;
}
int main()
{
    int n;
    si(n);
    int v[n];
    for(int i=0;i<n;i++)
        si(v[i]);
    
    for(int i=0;i<n;i++)
    {
        int temp = query(1,100000,1,v[i]-1,1);
        temp++;
        update(1,100000,v[i],1,temp);
    }
    
    int ans = tree[1];
    printf("%d",ans);
    return 0;
}
