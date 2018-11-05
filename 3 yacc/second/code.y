%{
#include<stdlib.h>
#include<stdio.h>
%}
%token DIGIT LETTER
%%
id:LETTER {printf("Valid identifiers\n");}
|id LETTER
|id DIGIT
;

%%
int main()
{
	printf("Enter the variable:\n");
	yyparse();
}

int yyerror(char *msg)
{
	printf("Invalid Character\n");
	exit(0);
	
}


