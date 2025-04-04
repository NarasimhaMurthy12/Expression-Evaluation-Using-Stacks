//Postfix Evaluation using stack
//By : P.Narasimha Murthy
//
//Procedure
//Create a stack to store operands (values).
//Scan the given expression from left to right and do the following for every element in array.
//	If the element is a number, push it into the stack.
//	If the element is an operator, pop operands for the operator from the stack. 
//	Evaluate the operator and push the result back to the stack.
//When the expression is ended, the number in the stack is the final answer.

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"main_header.h"

void postfix_eval(char *postfix)
{
	stacknode *stack=Createstackint();
	int len=strlen(postfix)-1;
	char *token;
	char *myPtr = strtok(postfix, " ");
	while(myPtr!=NULL)
	{
		token=myPtr;
		
		//if the token is a number or an alphabet, push it into the stack
		
		if (isalnum(token[0]))
		{
			int num=atoi(myPtr);
			pushint(stack,num);
		}
		//otherwise, it is an operator - so pop out the last 2 elemnets, perform the operation and push back into the stack

		else
		{
			int val1=pop_and_topint(stack);
			int val2=pop_and_topint(stack);

			if (token[0]=='+')
				pushint(stack,val1+val2);
			else if (token[0]=='-')
				pushint(stack,val2-val1);
			else if (token[0]=='*')
				pushint(stack,val1*val2);
			else if (token[0]=='/')
				pushint(stack,val2/val1);
		}
		myPtr = strtok(NULL," ");
	}
	printf("The value of the expresson is : %d\n",pop_and_topint(stack));

}
