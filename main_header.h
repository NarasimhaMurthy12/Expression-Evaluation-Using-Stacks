//By : Murthy
//Purpose : linked list implementation of stack

#include<stdio.h>
#include<stdlib.h>

typedef int elementtype;
typedef char *elementtype1;
struct node
{
	elementtype element;
	struct node *next;
};

typedef struct node stacknode;

struct node1
{
	elementtype1 element;
	struct node1 *next;
};

typedef struct node1 stacknode1;

stacknode *Createstackint();
int isEmptyint(stacknode *);
void pushint(stacknode *sta,elementtype x);
void popint(stacknode *sta);
elementtype topint(stacknode *sta);
elementtype pop_and_topint(stacknode *sta);


stacknode1 *Createstack();
int isEmpty(stacknode1 *);
void push(stacknode1 *,elementtype1 );
void pop(stacknode1 *sta);
elementtype1 top(stacknode1 *sta);
elementtype1 pop_and_top(stacknode1 *sta);


int precedence(char c);
char *infix_to_postfix(char *infix,char *postfix);


void postfix_eval(char *postfix);
