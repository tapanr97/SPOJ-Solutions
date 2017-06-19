#include <bits/stdc++.h>
using namespace std;
struct node
{
	int idx,val,idx1,l,chk;
};
struct node a[230005];
int tree[100005]={0};
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();
 
	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
bool cmp(const node &a,const node &b)
{
	if(a.val==b.val)
		return a.chk>b.chk;
	return a.val>b.val;
}
void build(int l,int r,int node)
{
	if(l==r)
	{
		tree[node] = 0;
		return;
	}
	int mid = (l+r)/2;
	build(l,mid,2*node);
	build(mid+1,r,2*node+1);
	tree[node] = tree[2*node]+tree[2*node+1];
}
void update(int pos,int l,int r,int node)
{
	if(l>r)
		return;
	if(l==r)
	{
		tree[node] = 1;
		return;
	}
	int mid = (l+r)/2; 
	if(pos<=mid)
		update(pos,l,mid,2*node);
	else
		update(pos,mid+1,r,2*node+1);
	tree[node] = tree[2*node]+tree[2*node+1];
}
int query(int l,int r,int tl,int tr,int node)
{
	
	if(tl>tr||l>tr||r<tl)
		return 0;
	if(l<=tl&&r>=tr)
		return tree[node];
	int mid = (tl+tr)/2;
	return query(l,r,tl,mid,2*node)+query(l,r,mid+1,tr,2*node+1);
}
int main() 
{
	int n,q,i,j;
	n = read();
	for(i=1;i<=n;i++)
	{
		int x;
		x = read();
		a[i].idx = i;
		a[i].chk = 0;
		a[i].val = x;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		int l,r,k;
		l = read();
		r = read();
		k = read();
		a[i+n].idx1 = i;
		a[i+n].l = l;
		a[i+n].idx = r;
		a[i+n].val = k;
		a[i+n].chk = 1;
	}
	sort(a+1,a+n+q+1,cmp);
	int ans[200005];
	build(1,n,1);
	for(i=1;i<=n+q;i++)
	{
		if(a[i].chk)
			ans[a[i].idx1] = query(a[i].l,a[i].idx,1,n,1);
		else
			update(a[i].idx,1,n,1);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}
