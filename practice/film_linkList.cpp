#include <stdio.h>
#include "Link_list.h"
#include <stdlib.h>
void showMovies(Item item);
char *str_gets(char *str, int n);

int film3(void)
{
	List movies;
	Item temp;

	InitializeList(&movies);
	if(ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available!\n");
		exit(1);
	}

	puts("Enter first movies title:");
	while(str_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while(getchar() != '\n')
			continue;
		if(AddItem(temp, &movies) == false)
		{
			fprintf(stderr,"Problem allocating memory.\n");
			break;
		}
		if(ListIsFull(&movies))
		{
			puts("The list is now full");
			break;
		}
		puts("Enter next title (empty line to stop):");
	}
	if(ListIsEmpty(&movies) == true)
		printf("No data enter");
	else
	{
		printf("Here is your movies list:\n");
		Traverse(&movies,showMovies);
	}
	printf("You enter %d movies.\n", ListItemCount(&movies));

	EmptyList(&movies);
	printf("Bye.\n");
}

void showMovies(Item item)
{
	printf("Movies: %s  Rating: %d\n", item.title, item.rating);
	/*将Rating: %d\n误写为Rating: %s\n，结果运行错误，打印不出电影列表*/
}