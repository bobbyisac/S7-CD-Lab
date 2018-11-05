#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	FILE *f1,*f2;
	char word[100],key[100];
	char op[6]={'+','-','*','/','%','='};
	char sc[6]="(){}:,";
	int lc=1,idcount=0,i=0;
	int flag1=0;
	f1=fopen("input.txt","r");
	printf("********************************************************\n");
	printf("SYMBOL TABLE\n");
	printf("********************************************************\n");
	printf("Line No.\tType\tValue\tID No.\n");
	while(!feof(f1))
	{
		fscanf(f1,"%s",word);
		if(isalpha(word[0]) || word[0]=='_')
		{
			f2=fopen("key.txt","r");
			while(!feof(f2))
			{
				fscanf(f2,"%s",key);
				if(strcmp(word,key)==0)
				{
					printf("%d\t\t%s\t%s\t%d\n",lc,"KEYWORD",word,++idcount);
					flag1=1;
					break;
				}
			}
			fclose(f2);
			if(flag1==0)
			{
				printf("%d\t\t%s\t%s\t%d\n",lc,"ID",word,++idcount);
			}
			flag1=0;
		}
		else if (isdigit(word[0]))
		{
			for(i=0;i<strlen(word);i++)
			{
				if(!isdigit(word[i]))
				{
					flag1=1;
					break;
				}
			}
			if(flag1==0)
			{
				printf("%d\t\t%s\t%s\t%d\n",lc,"NUM",word,++idcount);
			}
			flag1=0;
		}
		else if(strlen(word)==1)
		{
			for(i=0;i<6;i++)
			{
				if(word[0]==op[i])
				{
					printf("%d\t\t%s\t%s\t%d\n",lc,"OP",word,++idcount);
					flag1=1;
					break;
				}
			}
			if(flag1==0)
			{
				for(i=0;i<6;i++)
				{	
					if(word[0]==sc[i])
					{	
						printf("%d\t\t%s\t%s\t%d\n",lc,"Spec",word,++idcount);
						break;
					}
				}
			}
			flag1=0;
		}
		if(word[0]==';')
		{
			lc++;
		}
	}	
	fclose(f1);
	return 0;
}
