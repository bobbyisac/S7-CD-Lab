

#include
#include
#include
#include
void main()
{
int i,j,k,n,add=0,size;
char c,in[20],temp[20],val[20],var[20];
FILE*fp;
clrscr();
fp=fopen("input.c","r");
c=getc(fp);
printf('\n THE INPUT FILE IS:")
while(!feof(fp))
{
printf("%c",c);
c=getc(fp);
}
fclose(fp);
printf("\n**************symbol table**************");
printf("\n DAta type\tName\tNo.of Elements\tSize\tAddress");
printf("************************************");
while(!feof(fp))
{
if(isalpha(c))
{
i=0;
do
{
temp[i==]=c
c=getc(fp);
}while(isalpha(c));
temp[i]='\0';
if(strcmp("int",temp)==0)
{
strcpy(val," ");
strcpy(in," ");
strcpy(var," ");
while(c!=';')
{
strcpy(val," ");
c=getc(fp);
i=0;
do
{
var[i++]=c;
c=getc(fp);
}while(isalpha(c));
var[i]='\0';
if(c=='[')
{
i=0;
c=getc(fp);
strcpy(in," ")
do
{
in[i++]=c;
c=getc(fp);
k=atoi(in);
size=size*k;
}
else
{
strcpy(in,'1');
size=2;
}
if(c=='=')
c=getc(fp);
i=0;
do
{
val[i++]=c;
c=getc(fp);
}while(c!=','&&c!=';')
val[i]='\0';
}
printf("\n%s\t\t%s\t%s\t\t%s\t%dBytes\t%d",temp,var,val,in,size,add);
add=add+size;
}
}
}
else
c=getc(fp);
}
getch();
}
