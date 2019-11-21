#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * str_gets(char *str, int n);
char showmenu(void);
void eatline(void);      //������ĩβ
void show(void (*pf)(char *), char * str);
void toUpper(char *);//�ַ���ת��Ϊ��д��ĸ
void toLower(char *);//�ַ���ת��ΪСд��ĸ
void transpose(char *);//��Сдת��
void dummy(char *);//�������ַ���

int func_pointer(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfunc)(char *);//����һ������ָ��

	puts("Enter a string (empty line to quit):");
	while(str_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while((choice = showmenu()) != 'n')
		{
			switch(choice)
			{
			case 'u': pfunc = toUpper; break;
			case 'l': pfunc = toLower; break;
			case 't': pfunc = transpose; break;
			case 'o': pfunc = dummy; break;
			}
			strcpy(copy, line);
			show(pfunc, copy);
		}
		puts("Enter a string (empty to quit):");
	}
	puts("Bye.");

	return 0;

}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase            l) lowercse");
	puts("t) transpose case       o) original case");
	puts("n) next string");

	ans = getchar();
	ans = tolower(ans); 
	eatline();
	while(strchr("ulton", ans) == NULL)
	{
		puts("please enter a letter of u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void toUpper(char *str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void toLower(char *str)
{
	while(*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void transpose(char *str)
{
	while(*str)
	{
		if(islower(*str))
			*str = toupper(*str);
		else if(isupper(*str))
			*str = tolower(*str);	
		str++;
	}
}

void dummy(char *str)
{

}

void show(void (*pf)(char *str), char *str)
{
	(*pf)(str);
	puts(str);
}

