#include<stdio.h>
#include"main_header.h"

void main()
{
	char inpt[100];
	char postfi[100];
	printf("Enter the expression with spaces between th operand and operator : ");
	fgets(inpt,20,stdin);
	char *postfix=infix_to_postfix(inpt,postfi);
	postfix_eval(postfix);
}

