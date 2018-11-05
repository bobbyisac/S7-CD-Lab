#include<stdio.h>

static int n;
int i,j;
int main()
{
	scanf("%d",&n);
	
int a[n],flag[n];
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
	flag[i]=0;
}

for(i=1;i<=n;i++)
{
	for(j=0;j<n;j++)
	{
		if(i==a[j]) flag[j]=1;

	}
}
for(i=0;i<n;i++)
{
	if (flag[i]==0) {printf("no"); return 0;}
}
printf("yes");
return 0;
}
