#include <stdio.h>
#define STRLEN 14

void fgets1(){

	char words[STRLEN];

	puts("Please enter a string:");
	fgets(words, STRLEN, stdin);
	printf("Your string twice (puts(), then fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("Please enter another string:");
	fgets(words, STRLEN, stdin);
	printf("Your string twice (puts(), then fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("Done");

	 
}

#define STLEN 10
void fgets2(){

	char words[STLEN];

	puts("Enter strings (empty line to quit):");
	while(fgets(words,STLEN, stdin) != NULL && words[0] != '\n'){
	
		fputs(words, stdout);
	}
	puts("Done.");

}

void fgets3(){

	char words[STLEN];
	int i;

	puts("Enter strings (empty line to quit):");

	while(fgets(words, STLEN, stdin) != NULL && words[0] != '\n'){
	
		i = 0;
		while(words[i] != '\n' && words[i] != '\0')
			i++;
		if(words[i] == '\n')
			words[i] = '\0';
		else//如果words[i] == '\0'，丢弃输入行的剩余字符
			while(getchar() != '\n')
				continue;
		puts(words);
	}

	puts("Done.");
	

	

}