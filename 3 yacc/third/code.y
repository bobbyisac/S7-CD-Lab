%{
#include<stdlib.h>
#include<stdio.h>
%}
%token DIGIT

%%
stmt: expr {printf("result=%d\n",$$);}
expr: d '+' d {$$=$1+$3;}
|d '-' d {$$=$1-$3;}
|d '*' d {$$=$1*$3;}
|d '/' d {$$=$1/$3;}
|'(' d ')' {$$=$2;}
d:DIGIT {$$= $1;}
| expr {$$= $1;}
;

%%
int yyerror(char *msg)
{
	printf("Invalid Expresiion\n");
	exit(0);
}
int main()
{
	printf("Enter an expression: ");
	yyparse();
	//printf("Valid Expression\n");
}
