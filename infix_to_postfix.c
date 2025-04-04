//function to convert from infix to postfix

//By : P . Narasimha Murthy
//Date : 27/03/2025


//Below are the steps to implement the above idea:

//1.Scan the infix expression from left to right.
//2.If the scanned character is an operand, put it in the postfix expression.
//3.Otherwise, do the following
//4.If the precedence of the current scanned operator is higher than the precedence of the operator on top of the stack, or if the stack is empty, or if the stack contains a ‘(‘, then push the current operator onto the stack.
//5.Else, pop all operators from the stack that have precedence higher than or equal to that of the current operator. After that push the current operator onto the stack.
//6.If the scanned character is a ‘(‘, push it to the stack.
//7.If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
//8.Repeat steps 2-5 until the infix expression is scanned.
//9.Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
//10.Finally, print the postfix expression.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"main_header.h"

int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
	}
}


char  *infix_to_postfix(char *infix,char *postfix)
{
	int len=strlen(infix);
	stacknode1 *stack=Createstack();
	
	//traversing from left to right of the given expression
	
	char *myPtr = strtok(infix, " ");
	while(myPtr!=NULL)
	{		
		//If the token is an operand, add it to the postfix string

		char token=myPtr[0];
		if (isalnum(token))
		{
			strcat(postfix,myPtr);
			strcat(postfix," ");
		}

		//If the token is '(', add it to the stack
		
		else if(token=='(')
			push(stack,"(");

		//If the token is ')',keep popping and adding to the postfix string until '(' is encountered

		else if(token==')')
		{
			while((isEmpty(stack)!=1)&&(strcmp(top(stack),"(")!=0))
			{
				strcat(postfix,pop_and_top(stack));
				strcat(postfix," ");
			}
			pop(stack);
		}

		//If token is an operator
		
		else
		{
			while((isEmpty(stack)!=1)&&(precedence(token)<=precedence(top(stack)[0])))
			{
				strcat(postfix,pop_and_top(stack));
				strcat(postfix," ");
			}
			push(stack,myPtr);
		}
		myPtr = strtok(NULL, " ");
	}
	while(isEmpty(stack)!=1)
	{
		strcat(postfix,pop_and_top(stack));
		strcat(postfix," ");
	}
	printf("Postfix expression is : %s\n",postfix);
	free(stack);
	return postfix;
}


