#include<stdio.h>

static int nos;
int i,j;

int closure(char adj[nos][nos],int n,char state[nos])
{
	for(j=0;j<nos;j++)
	{
		if(adj[n][j]=='e')
		{
			if(n!=j)
			{
				printf("-->%c",state[j]);
				closure(adj,j,state);
			}
		}
	}
	return 0;
}

int main()
{
	printf("Enter the number of states: ");
	scanf("%d",&nos);
	char state[nos];
	printf("Enter the states: ");
	for(i=0;i<nos;i++)
	{
		getchar();
		state[i]=getchar();
	}
	char adj[nos][nos];
	for(i=0;i<nos;i++)
	{
		for(j=0;j<nos;j++)
		{
			printf("enter transition from %c to %c (z for no transition):",state[i],state[j]);
			getchar();
			adj[i][j]=getchar();
		}
	}
	for(i=0;i<nos;i++)
	{
		printf("Closure of %c : %c",state[i],state[i]);
		closure(adj,i,state);
		printf("\n");
	}
	return 0;
}
