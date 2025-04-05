#include<stdio.h>
#include"main_header.h"

void main()
{
	char inpt[50];
	char postfi[50];
	printf("Enter the expression with spaces between th operand and operator : ");
	fgets(inpt,50,stdin);
	char *postfix=infix_to_postfix(inpt,postfi);
	postfix_eval(postfix);
}

