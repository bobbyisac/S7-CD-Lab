#include<stdio.h>
#include<string.h>
int precedence(char s)
{
	if(s=='i')
	{
		return 0;
	}	
	else if(s=='+')
	{
		return 1;
	}
	else if(s=='*')
	{
		return 2;
	}
	else if(s=='$')
	{
		return 3;
	}
}
void main(){
	int i,j,top=0,k;
	char arr[4][4]={'e','>','>','>','<','>','<','>','<','>','>','>','<','<','<','a'}, stack[10],input[10],val,op;
		stack[0]='$';
	printf("Precedence Table is:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%c \t",arr[i][j]);
		}
		printf("\n");
	}
	printf("Enter the Input\n");
	gets(input);
	//strcpy(input,"i+i*i$");
	//printf("%s",input);
	for(k=0;input[k]!='\0';)
	{
		op=arr[precedence(stack[top])][precedence(input[k])];
		//printf("%c",op);
		if(op=='<')
		{	
	
			stack[++top]=input[k];
			k++;	
		}
		else if(op=='>')
		{
			val=stack[top];
			top--;

		}
		else if(op=='a')
		{
			printf("Accepted");
			break;
		}
		else if(op=='e')
		{
			printf("Invalid");
			break;
		}
	}
	
	
	
	
}
