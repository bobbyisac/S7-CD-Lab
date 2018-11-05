#include<stdio.h>
#include<string.h>

int i=0,j=0,z=0,c=0;
char a[20],ac[20],stk[20],act[20];

void parse()
{
	strcpy(ac,"reduce to E");
	for(z=0; z<c; z++)
       		if(stk[z]=='i' && stk[z+1]=='d')
         	{
           		stk[z]='E';
           		stk[z+1]='\0';
           		printf("$%s\t%s$\t%s\n",stk,a,ac);
           		j++;
         	}
     	for(z=0; z<c; z++)
       		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E')
         	{
           		stk[z]='E';
           		stk[z+1]='\0';
           		stk[z+2]='\0';
           		printf("$%s\t%s$\t%s\n",stk,a,ac);
           		i=i-2;
         	}
     	for(z=0; z<c; z++)
       		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E')
         	{
           		stk[z]='E';
           		stk[z+1]='\0';
           		stk[z+1]='\0';
           		printf("$%s\t%s$\t%s\n",stk,a,ac);
           		i=i-2;
         	}
     	for(z=0; z<c; z++)
       		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
         	{
           		stk[z]='E';
           		stk[z+1]='\0';
           		stk[z+1]='\0';
           		printf("$%s\t%s$\t%s\n",stk,a,ac);
           		i=i-2;
         	}
}

int main()
{
	printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id\n");
      	printf("input: ");
      	scanf("%s",a);
      	c=strlen(a);
      	strcpy(act,"SHIFT->");
      	printf("Stack\t\tInput\t\tAction\n-----------------------------------------\n");
      	for(i=0;j<c+1;i++,j++)
       	{
         	if(a[j]=='i' && a[j+1]=='d')
           	{
              		stk[i]=a[j];
              		stk[i+1]=a[j+1];
              		stk[i+2]='\0';
              		a[j]=' ';
              		a[j+1]=' ';
              		printf("$%s\t%s$\t%sid\n",stk,a,act);
              		parse();
           	}
         	else
           	{
              		stk[i]=a[j];
              		stk[i+1]='\0';
              		a[j]=' ';
              		printf("$%s\t%s$\t%ssymbols\n",stk,a,act);
              		parse();
           	}
       	}
	if(stk[0]=='E' && stk[1]=='\0')
		printf("Accept\n");
	else
		printf("Reject\n");
}
