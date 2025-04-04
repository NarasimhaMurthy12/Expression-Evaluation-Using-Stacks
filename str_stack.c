#include"main_header.h"


stacknode1 *Createstack()
{
	stacknode1 *s1=malloc(sizeof(stacknode1));
	if (s1!=NULL)
	{
		s1->next=NULL;
		return s1;
	}
	printf("Out of memory\n");
}

int isEmpty(stacknode1 *sta)
{
	return sta->next==NULL;
}


void push(stacknode1 *sta,elementtype1 x)
{
	stacknode1 *tmp=Createstack();
	tmp->element=x;
	tmp->next=sta->next;
	sta->next=tmp;
}

void pop(stacknode1 *sta)
{
	if (isEmpty(sta))
		printf("Stack is empty\n");
	else
	{
		stacknode1 *tmp=sta->next;
		sta->next=tmp->next;
		free(tmp);

	}
}

void makeempty(stacknode1 *sta)
{
	printf("Making empty\n");
	while(!isEmpty(sta))
	{
		pop(sta);
	}
	sta->next=NULL;
}

elementtype1 top(stacknode1 *sta)
{
	if(isEmpty(sta))
		printf("Stack is empty\n");
	else
	{
		return sta->next->element;
	}
}

elementtype1 pop_and_top(stacknode1 *sta)
{
	if(isEmpty(sta))
		printf("Stack is empty\n");
	else
	{
		char *dat;
		dat=sta->next->element;
		pop(sta);
		return dat;
	}
}

void Display(stacknode1 *sta)
{
	if (isEmpty(sta))
		printf("stack is empty\n");
	else
	{
		printf("The stack has : \n");
		stacknode1 *tmp=sta->next;
		while(tmp!=NULL)
		{
			printf("%s\n",tmp->element);
			tmp=tmp->next;
		}

	}
}

