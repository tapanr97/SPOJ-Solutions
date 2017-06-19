#include <bits/stdc++.h>
using namespace std;
bool primeSieve[32001];

void sieve()
{
	for(int i=0;i<=32000;i++)
		primeSieve[i] = true;
	primeSieve[0] = primeSieve[1] = false;
	for(int i=2;i*i<=32000;i++)
	{
		for(int j=i*i;j<=32000;j+=i)
			primeSieve[j] = false;
	}
}
int main() 
{
	int t;
	scanf("%d",&t);
	sieve();
	while(t--)
	{
		int n,m;
		scanf("%d %d",&m,&n);
		if(n<=32000)
		{
			for(int i=m;i<=n;i++)
			{
				if(primeSieve[i])
					printf("%d\n",i);
			}
		}
		else
		{
			if(m<=32000)
			{
				for(int i=m;i<=32000;i++)
				{
					if(primeSieve[i])
						printf("%d\n",i);
				}
			}
			if(m<2)
				m = 2;
			bool primeSeg[100001];
			for(int i=0;i<=100000;i++)
				primeSeg[i] = true;
			for(int i=2;i<=32000;i++)
			{
				if(primeSieve[i])
				{
					int loLim = floor(m/i) *i;
            		if (loLim < m)
            			loLim += i;
					for(int j=loLim;j<=n;j+=i)
						primeSeg[j-m] = false;
				}
			}
			for(int i=m;i<=n;i++)
			{
				if(primeSeg[i-m])
					printf("%d\n",i);
			}
		}
		printf("\n");
	}
	return 0;
}
