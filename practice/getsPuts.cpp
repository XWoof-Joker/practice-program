#include <stdio.h>

#define STRLEN 5

void getsPuts(){

	char word[STRLEN];
	puts("Please enter a string:");
	gets(word);
	puts("Your string twices:");
	printf("%s\n",word);
	puts(word);
	puts("Done!");

}

