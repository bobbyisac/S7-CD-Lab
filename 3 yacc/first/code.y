%{
#include<stdlib.h>
#include<stdio.h>
%}
%token DIGIT LETTER OP OB CB

%%
s:id|num|ob;
ob:OB s CB;
id:id op id|num op num|LETTER;
num:DIGIT;
op:OP;

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
	printf("Valid Expression\n");
}
