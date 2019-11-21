#ifndef _STACK_H_
#define _STACK_H_

#define MAXSIZE 100

typedef int Item;

typedef struct stackNode{
	Item item;
	struct stackNode *next;
}StackNode, *Stack;

/*º¯ÊýÔ­ÐÍ*/

void InitializeStack(Stack *pstack);

bool StackIsEmpty(const Stack *pstack);

bool StackIsFull(const Stack *pstack);

unsigned int StackItemCount(const Stack *pstack);

bool Pop(Stack *pstack);

bool Push(Item *item, Stack *pstack);

bool GetTop(const Stack *pstack, Item *item);

void StackTraverse(Stack *pstack, void (*pfun)(Item item));

void EmptyStack(Stack *pstack);



#endif