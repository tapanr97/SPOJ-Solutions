#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define inchar          getchar_unlocked
#define outchar(x)      putchar_unlocked(x)

template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}

const int N = 111111;
const int LN = 19;
vector<int> g[N];
int costs[N];
int n,m,ptr;
int lev[N],p[N][LN];
map<int,int> M;
int RM[N];

struct node
{
	int cnt;
	node* left,* right;
	node(){}
	node(int c,node* l,node* r)
	{
		cnt = c;
		left = l;
		right = r;
	}
};

node* version[N];
void build(node* n,int l,int r)
{
	if(l==r)
	{
		n->cnt = 0;
		return;
	}
	int mid = (l+r)/2;
	n->left = new node(0,NULL,NULL);
	n->right = new node(0,NULL,NULL);
	build(n->left,l,mid);
	build(n->right,mid+1,r);
	n->cnt = n->left->cnt + n->right->cnt;
}

void upgrade(node *prev,node* cur,int l,int r,int pos)
{
	if(pos>r || pos<l || l>r)
		return;
	if(l==r)
	{
		cur->cnt = prev->cnt+1;
		return;
	}
	int mid = (l+r)/2;
	if(pos<=mid)
	{
		cur->right = prev->right;
		cur->left = new node(0,NULL,NULL);
		upgrade(prev->left,cur->left,l,mid,pos);
	}
	else
	{
		cur->left = prev->left;
		cur->right = new node(0,NULL,NULL);
		upgrade(prev->right,cur->right,mid+1,r,pos);
	}
	cur->cnt = cur->left->cnt + cur->right->cnt;
}

int query(node* a,node* b,node* c,node* d,int l,int r,int k)
{
	if(l==r)
		return l;
	int count = a->left->cnt + b->left->cnt - c->left->cnt - d->left->cnt;
	int mid = (l+r)/2;
	if(count>=k)
		return query(a->left,b->left,c->left,d->left,l,mid,k);
	else
		return query(a->right,b->right,c->right,d->right,mid+1,r,k-count);
}

void dfs(int u,int pa,int d=0)
{
	p[u][0] = pa;
	lev[u] = d;
	version[u] = new node(0,NULL,NULL);
	upgrade(version[pa],version[u],1,ptr,M[costs[u]]);
	for(int i=0;i<g[u].size();i++)
	{
		if(g[u][i]!=pa)
			dfs(g[u][i],u,d+1);
	}
}

int lca(int u,int v)
{
	if(lev[u]<lev[v])
		swap(u,v);
	int diff = lev[u]-lev[v];
	for(int i=0;i<LN;i++)
	{
		if((diff>>i)&1)
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

int main()
{
	ptr = 1;
	inpos(n);
	inpos(m);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<LN;j++)
			p[i][j] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		inpos(costs[i]);
		M[costs[i]];
	}
	map<int,int> :: iterator it;
	for(it = M.begin(); it!=M.end(); it++)
	{
		M[it->first] = ptr;
		RM[ptr] = it->first;
		ptr++;
	}
	ptr--;

	node* root = new node(0,NULL,NULL);
	build(root,1,ptr);
	version[0] = root;

	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		inpos(u);
		inpos(v);
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1,0);
	for(int j=1;j<LN;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(p[i][j-1]!=0)
				p[i][j] = p[p[i][j-1]][j-1];
		}
	}
	
	while(m--)
	{
		int u,v,k;
		inpos(u);
		inpos(v);
		inpos(k);
		int LCA = lca(u,v);
		int ans = query(version[u],version[v],version[LCA],version[p[LCA][0]],1,ptr,k);
		outpos(RM[ans]);
	}
	return 0;
}
