#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45  //储存电影名的数组大小

typedef struct film {
	char title[TSIZE];
	int rating;
	struct film *next;
}FILM, *PFILM;

char *str_gets(char *str, int n);

void linkListOfFilm(void)
{
	PFILM head = NULL;
	PFILM previous, current;
	char temp[TSIZE];

	puts("Please enter the first film name:");
	while (str_gets(temp, TSIZE) != NULL && temp[0] != '\0')
	{
		current = (PFILM)malloc(sizeof(FILM));
		if(head == NULL)
			head = current;
		else
			previous->next = current;
		current->next = NULL;
		strcpy(current->title, temp);
		puts("Enter the rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter the next film name (empty line to stop):");
		previous = current;
	}

	if(head ==NULL)
		puts("No data enter.");
	else
		puts("Here is your film list:");
	current = head;
	while(current != NULL)
	{
		printf("Movie: %s    Rating: %d\n",
			current->title, current->rating);
		current = current->next;
	}

	//释放已分配的内存
	current = head;
	while(current != NULL)
	{
		current = head;
		head = current->next;
		free(current);
	}
	puts("Bye.");

}