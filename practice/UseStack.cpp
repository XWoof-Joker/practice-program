#include <stdio.h>
#include "stack.h"

void showItems(Item item);

int UseStack(void)
{
	Stack s;
    Item temp;

	InitializeStack(&s);

	puts("Please enter a number:");
	for (int j = 0; j < 10;j++)
	{
		scanf("%d", &temp);
		Push(&temp, &s);
		puts("Please enter next number:");
	}

	printf("Stack Item count: %d\n", StackItemCount(&s));
	GetTop(&s, &temp);
	printf("%d \n", temp);
	StackTraverse(&s,showItems);

	puts("Now pop 4 items.");
	for(int i = 0; i < 4; i++)
		Pop(&s);

	printf("Stack Item count: %d\n", StackItemCount(&s));
	StackTraverse(&s,showItems);

	EmptyStack(&s);

	return 0;
}

void showItems(Item item)
{
	printf("%d  ", item);
}