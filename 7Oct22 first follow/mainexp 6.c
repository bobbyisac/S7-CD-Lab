#include<stdio.h> 
char gram[8][35]={"E->TD","D->+TD","D->#","T->FS","S->*FS","S->#","F->(E)","F->i"}; 
char ter[10]={'+','#','*','(',')','i'}; 
char nonter[10]={'E','T','D','F','S'}; 
char fir[10],fol[10]; 
int fi=0,fo=0,k; 
int ister(char b) 
{
    int i;
    for(i=0;i<6;i++)
        if(b==ter[i])
        	return 1;        
    return 0;
 }
int First(char a)
{    
	int i,j;   
 	if(ister(a))
    	{
       		fir[fi]=a;
        	fi++;
    	}
   	else
    	{ 
      		 for(i=0;i<8;i++)
       		 { 
          		if(gram[i][0]==a)
           			  if (gram[i][3]=='#') 
				  {
					fir[fi]='#';
					fi++;
				  }  
			else
				 	First(gram[i][3]);
       		  }
        }
} 

int Follow(char x)
{
    int i,j;
    if(x=='E') 
    { 
      	 fol[fo]='$';
    	 fo++;
    }
   for(i=0;i<8;i++)
   {
        for(j=3;gram[i][j]!='\0';j++) 
        { 
           if(gram[i][j]==x) 
           {  
              if(gram[i][j+1]=='\0') 
              { 
                   Follow(gram[i][0]); 
                   return;
              }  
              else 
              { 
                   fi=0;
                   First(gram[i][j+1]);
    		   for(k=0;k<fi;k++)
                   { 
                       if(fir[k]!='#') 
                       { 
                           fol[fo]=fir[k];
                           fo++; 
                       } 
                       else 
                       {  
                          Follow(gram[i][0]);
                          return;
                       }
                   }
              } 
           }
        } 
   } 
}
int main()
{    
	int i,j;
 	char val;   
	printf("First: \n");
	for(i=0;i<5;i++) 
  	{ 
       	 	 printf("First of %c:",nonter[i]);
       		 First(nonter[i]);
       		 for(j=0;j<fi;j++)
       		 { 
         		  printf(" %c,",fir[j]);
        	 }
        	 fi=0;
		 printf("\b \b\n");
    	} 
	printf("\nFollow:\n");
   	for(i=0;i<5;i++)
    	{ 
      		 printf("Follow of %c:",nonter[i]); 
      		 Follow(nonter[i]);
       		 for(j=0;j<fo;j++)
        	 {
           		 printf(" %c,",fol[j]);
      		 } 
       		 fo=0;
		 printf("\b \b\n");
   	} 
   return 0;
}
