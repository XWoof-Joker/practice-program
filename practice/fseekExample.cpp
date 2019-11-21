#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81

void fseekExample(void)
{
	char file[SLEN];
	char ch;
	FILE *fp;
	long count, last;

	puts("Enter the file name to be processed:");
	scanf("%80s", file);
	if ((fp = fopen(file,"rb")) == NULL)
	{
		printf("Can't open file：%s\n", file);
		exit(EXIT_FAILURE);
	}

	fseek(fp,0L,SEEK_END);              //定位到文件末尾
	last = ftell(fp);
	for (count = 1L; count <= last; count++)
	{
		fseek(fp,-count,SEEK_END);     //回退
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r')   //MS-DOS 文件
			putchar(ch);
	}
	putchar('\n');

	fclose(fp);

}
