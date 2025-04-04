#include"main_header.h"
//Stack functions for evaluation(integer)
stacknode *Createstackint()
{
	stacknode *s1=malloc(sizeof(stacknode));
	if (s1!=NULL)
	{
		s1->next=NULL;
		return s1;
	}
	printf("Out of memory\n");
}

int isEmptyint(stacknode *sta)
{
	return sta->next==NULL;
}


void pushint(stacknode *sta,elementtype x)
{
	stacknode *tmp=malloc(sizeof(stacknode));
	tmp->element=x;
	tmp->next=sta->next;
	sta->next=tmp;
}

void popint(stacknode *sta)
{
	if (isEmptyint(sta))
		printf("Stack is empty\n");
	else
	{
		stacknode *tmp=sta->next;
		sta->next=tmp->next;
		free(tmp);

	}
}

elementtype topint(stacknode *sta)
{
	if(isEmptyint(sta))
		printf("Stack is empty\n");
	else
	{
		return sta->next->element;
	}
}

elementtype pop_and_topint(stacknode *sta)
{
	if(isEmptyint(sta))
		printf("Stack is empty\n");
	else
	{
		elementtype dat;
		dat=sta->next->element;
		popint(sta);
		return dat;
	}
}

