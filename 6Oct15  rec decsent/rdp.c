#include<stdio.h>
#include<stdlib.h>

char l;
int count=0;
char s[10];

void E();

void match(char t)
{
	if(l==t)
		l=s[++count];
	else
	{
		printf("Unsuccessful!\n");
		exit(0);
	}
}

void F()
{
	if(l=='(')
	{
		match('(');
		E();
		match(')');
	}
	else
		match('i');
}

void Tdash()
{
	if(l=='*')
	{
		match('*');
		F();
		Tdash();
	}
	else
		return;
}

void T()
{
	F();
	Tdash();
}

void Edash()
{
	if(l=='+')
	{
		match('+');
		T();
		Edash();
	}
	else
		return;
}

void E()
{
	T();
	Edash();
}

int main()
{
	scanf("%s",s);
	l=s[count];
	E();
	if(l=='$')
	{
		printf("Successfully Parsed!\n");
		return 0;
	}
	printf("Parsing Unsuccessful!\n");
	return 0;
}
