#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "binaryTree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);
char *str_gets(char *str, int n);

int useTreeToStorePet(void)
{
	Tree pets;
	char choice;

	initializeTree(&pets);
	while((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 'a': addpet(&pets);
			break;
		case 'l': showpets(&pets);
			break;
		case 'f': findpet(&pets);
			break;
		case 'n': printf("%d pets in club\n",treeItemCount(&pets));
			break;
		case 'd': droppet(&pets);
			break;
		default: puts("Switching error.");
		}
	}
	DeleteAll(&pets);
	puts("Bye.");

	return 0;
}

char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Menbership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a)  add a pet         l)  show list of pets");
	puts("n)  number of pets    f)  find pets");
	puts("d)  delete apet       q)  quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("alrnfdq", ch) == NULL)
		{
			puts("Please enter an a, l, n, f, d, or q:");
		}
		else
			break;
	}
	if(ch == EOF)
		ch = 'q';

	return ch;
}

void addpet(Tree *pt)
{
	Item temp;

	if (treeIsFull(pt))
		puts("No room in the club!");
	else
	{
		puts("Please enter name of pet:");
		str_gets(temp.petname, SLEN);
		puts("Please enter pet kind:");
		str_gets(temp.petkind, SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind);
		AddItem(&temp, pt);
	}

}

void showpets(const Tree *pt)
{
	if (treeIsEmpty(pt))
		puts("No entries!");
	else
		TraverseTree(pt, printitem);
}

void printitem(Item item)
{
	printf("Pets: %-19s  Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt)
{
	Item temp;

	if (treeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find:");
	str_gets(temp.petname, SLEN);
	puts("Please enter pet kind:");
	str_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);

	printf("%s the %s ", temp.petname, temp.petkind);
	if (InTree(&temp, pt))
		printf("is a menber.\n");
	else 
		printf("is not a menber.\n");
}

void droppet(Tree *pt)
{
	Item temp;

	if(treeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	str_gets(temp.petname, SLEN);
	puts("Please enter peet kind:");
	str_gets(temp.petkind, SLEN);
	uppercase(temp.petname);
	uppercase(temp.petkind);
	printf("%s the %s ",temp.petname, temp.petkind);
	if (DeleteItem(&temp, pt))
		printf("is droped from the club.\n");
	else
		printf("is not menber.\n");
}

void uppercase(char *str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

