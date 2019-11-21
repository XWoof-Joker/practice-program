#include <stdio.h>
#include <string.h>
#define SIZE 81             /*限制字符串长度*/
#define STRLINE 20          /*可以读入的字符串行数*/
#define HALT ""             /*空字符串停止输入*/
void strSort(char *strings[], int num);    /*字符串排序函数*/
char *string_gets(char *str, int n);

void sort_string(void)
{
	char input[STRLINE][SIZE];      /*储存输入的数组      */
	char *ptstr[STRLINE];			/*内含指针变量的数组  */
	int count = 0;

	printf("Input up to %d lines, and I will sort them.\n", STRLINE);
	printf("To stop, press the [Enter] key at a line's start.\n");
	while (count < STRLINE && string_gets(input[count], SIZE) != NULL && input[count][0] != '\0')
	{
		ptstr[count] = input[count];
		count++;
	}
	strSort(ptstr, count);
	puts("\nHere is the sorted list:");
	for (int i = 0; i < count; i++)
	{
		puts(ptstr[i]);
	}

}

void strSort(char *strings[], int num)
{
	char *temp;
	int top,seek;

	for (top = 0; top < num - 1; top++)
		for (seek = 0; seek < num - 1 - top; seek++)
			if (strcmp(strings[seek],strings[seek+1]) > 0)
			{
				temp = strings[seek];
				strings[seek] = strings[seek+1];
				strings[seek+1] = temp;
			}
}

char *string_gets(char *str, int n)
{
	char *ret_val;
	char *ch;

	ret_val = fgets(str, n, stdin);
	if(ret_val)
	{
		ch = strchr(str, '\n');
		if (ch)
			*ch = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

