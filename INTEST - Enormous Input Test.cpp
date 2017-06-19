#include<stdio.h>
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 int cnt=0;
 while(n--)
 {
  int num;
  scanf("%d",&num);
  if(num%k==0)cnt++; 
 }    
 printf("%d",cnt);
 return 0;
}
