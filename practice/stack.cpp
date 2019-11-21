#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

static void CopyItem(Item *item, StackNode *node);

void InitializeStack(Stack *pstack)
{
	*pstack = NULL;
}

bool StackIsEmpty(const Stack *pstack)
{
	if(pstack == NULL)
		return true;
	else
		return true;
}

bool StackIsFull(const Stack *pstack)
{
	/*StackNode *newNode;
	bool isFull;
	newNode = (StackNode *)malloc(sizeof(StackNode));
	if (newNode == NULL)
		isFull = true;
	else
		isFull = false;

	free(newNode);
	return isFull;*/
	if (StackItemCount(pstack) == MAXSIZE)
		return true;
	else
		return false;
}

unsigned int StackItemCount(const Stack *pstack)
{
	unsigned int count = 0;
	StackNode *scan;
	scan = *pstack;

	while (scan != NULL)
	{
		count++;
		scan = scan->next;
	}
		
	return count;
}

bool Push(Item *item, Stack *pstack)
{
	StackNode *newNode;

	if (StackIsFull(pstack))
	{
		fprintf(stderr, "The stack is full!\n");
		exit(1);
	}
	newNode = (StackNode *)malloc(sizeof(StackNode));
	if (newNode == NULL)
		return false;

	CopyItem(item, newNode);

	if (*pstack == NULL)
	{
		*pstack = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *pstack;
		*pstack = newNode;
	}

	return true;
}

bool Pop(Stack *pstack)
{
	StackNode *top;

	if (*pstack == NULL)
		return false;
	top = *pstack;
	*pstack = (*pstack)->next;
	free(top);

	return true;

}

bool GetTop(const Stack *pstack, Item *item)
{
	if (*pstack == NULL)
	{
		fprintf(stderr, "Stack is empty, there is no data.\n");
		return false;
	}

	*item = (*pstack)->item;

	return true;
}

void StackTraverse(Stack *pstack, void (*pfun)(Item item))
{
	StackNode *scan;
	scan = *pstack;

	while (scan != NULL)
	{
		(*pfun)(scan->item);
		scan = scan->next;
	}
}

void EmptyStack(Stack *pstack)
{
	while (*pstack != NULL)
		Pop(pstack);
}

static void CopyItem(Item *item, StackNode *node)
{
	node->item = *item;
}
