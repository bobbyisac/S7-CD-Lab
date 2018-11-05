#include<stdio.h>
#include<ctype.h>
#include<string.h>

void followfirst(char,int,int);
void follow(char);
void findfirst(char,int,int);
int count,n=0,m=0,k,ck,e;
char calc_first[10][100],calc_follow[10][100],prod[10][10],f[10],first[10];

int main()
{
	int jm=0,km=0,i,choice,kay,ptr=-1,point1=0,point2,xxx,land=0;
	char c,ch,done[count],donee[count];
	count=8;
	strcpy(prod[0],"E=TD"); 
    	strcpy(prod[1],"D=+TD"); 
    	strcpy(prod[2],"D=#"); 
    	strcpy(prod[3],"T=FS"); 
    	strcpy(prod[4],"S=*FS"); 
    	strcpy(prod[5],"S=#"); 
    	strcpy(prod[6],"F=(E)"); 
    	strcpy(prod[7],"F=i"); 

	for(k=0;k<count;k++)
		for(kay=0;kay<100;kay++)
			calc_first[k][kay]='!';
	for(k=0;k<count;k++)
	{ 
        	c=prod[k][0]; 
        	point2=0; 
        	xxx=0; 
        	for(kay=0;kay<=ptr;kay++) 
            		if(c==done[kay]) 
                		xxx=1; 
        	if(xxx==1) 
            		continue;      
        	findfirst(c,0,0); 
        	ptr+=1; 
        	done[ptr]=c; 
        	printf("First(%c) = ",c); 
        	calc_first[point1][point2++]=c; 
        	for(i=0+jm;i<n;i++) 
		{ 
            		int lark=0,chk=0; 
            		for(lark=0;lark<point2;lark++) 
			{ 
                		if(first[i]==calc_first[point1][lark]) 
                		{ 
                    			chk=1; 
                    			break; 
                		} 
            		} 
            		if(chk==0) 
            		{ 
                		printf("%c,",first[i]); 
                		calc_first[point1][point2++]=first[i]; 
            		} 
        	} 
        	printf("\b \b\n"); 
        	jm=n; 
        	point1++; 
    	} 
    	printf("\n"); 
    	ptr=-1; 
    	for(k=0;k<count;k++)
	        for(kay=0;kay<100;kay++)
	            calc_follow[k][kay]='!'; 
    	point1=0; 
    	for(e=0;e<count;e++) 
    	{ 
        	ck=prod[e][0]; 
        	point2=0; 
        	xxx=0; 
        	for(kay=0;kay<=ptr;kay++) 
            		if(ck==donee[kay]) 
                		xxx=1; 
        	if(xxx==1) 
	            continue; 
        	land+=1;  
        	follow(ck);
        	ptr+=1; 
	        donee[ptr] = ck; 
	        printf("Follow(%c) = ",ck); 
	        calc_follow[point1][point2++] = ck; 
        	for(i=0+km;i<m;i++)
		{ 
            		int lark=0,chk=0; 
            		for(lark=0;lark<point2;lark++)  
            		{ 
                		if(f[i]==calc_follow[point1][lark]) 
                		{ 
                    			chk=1; 
                    			break; 
                		}
            		}
            		if(chk==0) 
            		{ 
                		printf("%c,",f[i]); 
                		calc_follow[point1][point2++]=f[i]; 
            		} 
        	} 
        	printf("\b \b\n"); 
        	km=m; 
        	point1++;  
    	}
}

void follow(char c)
{
	int i,j;
	if(prod[0][0]==c)
		f[m++]='$';
	for(i=0;i<10;i++)
	{
		for(j=2;j<10;j++)
		{
			if(prod[i][j]==c)
			{
				if(prod[i][j+1]!='\0')
					followfirst(prod[i][j+1],i,j+2);
				if(prod[i][j+1]=='\0' && c!=prod[i][0])
				follow(prod[i][0]);
			}
			
		}
	}
}

void findfirst(char c, int q1, int q2)
{
	int j;
	if(!(isupper(c)))
	{
		first[n++]=c;
	}
	for(j=0;j<count;j++)
	{
		if(prod[j][0]==c)
		{
			if(prod[j][2]=='#')
			{
				if(prod[q1][q2]=='\0')
					first[n++]='#';
				else if(prod[q1][q2]=='\0' && q1!=0 || q2!=0)
					findfirst(prod[q1][q2],q1,(q2+1));
				else
					first[n++]='#';
			}
			else if(!isupper(prod[j][2]))
				first[n++]=prod[j][2];
			else
				findfirst(prod[j][2],j,3);
		}
	}
	
}

void followfirst(char c, int c1, int c2)
{
	int k;
	if(!(isupper(c)))
		f[m++]=c;
	else
	{
		int i=0,j=1;
		for(i=0;i<count;i++)
		{
			if(calc_first[i][0]==c)
				break;
		}
		while(calc_first[i][j]!='!')
		{
			if(calc_first[i][j]!='#')
				f[m++]=calc_first[i][j];
			else
			{
				if(prod[c1][c2]=='\0')
					follow(prod[c1][0]);
				else
					followfirst(prod[c1][c2],c1,c2+1);
			}
			j++;
		}
	}
}
