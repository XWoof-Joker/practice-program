#include <stdio.h>
#include <string.h>
#define SIZE 80
char * s_gets(char * st, int n);

void str_cat(){

	char str[SIZE];
	char add_str[] = "s smell like sun";

	puts("What's you favorite flower?");
	if(s_gets(str,SIZE)){
	
		strcat(str, add_str);
		puts(str);
		puts(add_str);
	}
	else
		puts("End of file encountered!");
	puts("Bye");

}

char * s_gets(char *st, int n){

	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if(ret_val){
	
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}

/*拼接字符串，检查第一个数组大小*/
#define SIZE_2 30
#define BUGSIZE 13

int strcat_checkLen(){

	char flower[SIZE_2];
	char addStr[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;

	puts("Whats your favorite flower?");
	s_gets(flower,SIZE_2);
	if(strlen(flower) + strlen(addStr) + 1 <= SIZE_2)
		strcat(flower, addStr);	
	puts(flower);

	puts("enter a bug problem?");
	s_gets(bug,BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addStr,available);
	puts(bug);

	return 0;
}