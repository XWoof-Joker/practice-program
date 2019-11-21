/*结构体的使用*/
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
char *str_gets(char * st, int n);
#define MAXTITL 40        /*最长书名*/
#define MAXAUTL 40        /*最长作者名*/
#define MAXBKS 100        /*最大书籍数*/ 

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float price;
};

int structManyBook(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Press [Enter] at the start of a line to stop.\n");
	printf("Please enter the book title:\n");
	
	while (count < MAXBKS && str_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the auther.\n");
		str_gets(library[count].author, MAXAUTL);
		printf("Now enter the price:\n");
		scanf("%f",&library[count++].price);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title:\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, 
				library[index].author, library[index].price);
		}
	}
	else
		printf("No books?Too bad.\n");

	return 0;
}

char *str_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);

	if (ret_val)
	{
		find = strchr(st, '\n');//查找换行符
		if (find)               //如果地址不是NULL
			*find = '\0';       //在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue;       //忽略输入行的剩余字符
	}

	return ret_val;
}

/*把结构成员作为参数传递*/
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);

void funds(void)
{
	struct funds stan = {
		"Garlic-Melon bank",
		4032.23,
		"Lucky's Savings and Loan",
		8543.34
	};

	printf("Stan has a total of $%.2f.\n",
		sum(stan.bankfund, stan.savefund));
}

double sum(double a, double b)
{
	return (a + b);
}

//传递结构地址
double sum(const struct funds *);

void funds2(void)
{
	struct funds stan = {
		"Garlic-Melon bank",
		4032.23,
		"Lucky's Savings and Loan",
		8543.34
	};

	printf("Stan has a total of $%.2f.\n", sum(&stan));
}

double sum(const struct funds *money)
{
	return ((*money).bankfund + money->savefund);
}

//使用指向结构的指针
#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

void getInfo(struct namect *);
void makeInfo(struct namect *);
void showInfo(const struct namect *);

int names1(void)
{
	struct namect person;

	getInfo(&person);
	makeInfo(&person);
	showInfo(&person);

	return 0;
}

void getInfo(struct namect * pst)
{
	printf("Please enter your first name:\n");
	str_gets(pst->fname, NLEN);
	printf("Then enter last your name;\n");
	str_gets(pst->lname, NLEN);
}

void makeInfo(struct namect * pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showInfo(const struct namect * pst)
{
	printf("%s %s,your name contain %d letters.\n",
		pst->fname, pst->lname, pst->letters);
}

//传递并返回结构
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

void names2(void)
{
	struct namect person;

	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

}

struct namect getinfo(void)
{
	struct namect temp;
	printf("Please enter your first name:\n");
	str_gets(temp.fname,NLEN);
	printf("Then enter your last name:\n");
	str_gets(temp.lname, NLEN);

	return temp;
}

struct namect makeinfo(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);

	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, your name contains %d letters.\n",
		info.fname, info.lname, info.letters);
}

/*names3()--使用指针和malloc()*/
#define SLEN 100

struct namect2 {
	char *fname;
	char *lname;
	int letters;
};

void getInfo2(struct namect2 *);
void makeInfo2(struct namect2 *);
void showInfo2(const struct namect2 *);
void cleanUp(struct namect2 *);

void names3(void)
{
	struct namect2 person;
	getInfo2(&person);
	makeInfo2(&person);
	showInfo2(&person);
	cleanUp(&person);
}

void getInfo2(struct namect2 *pst)
{
	char temp[SLEN];
	printf("Please enter your first name:\n");
	str_gets(temp,SLEN);
	pst->fname = (char *)malloc(strlen(temp) + 1);
	strcpy(pst->fname,temp);
	printf("Then enter your last name:\n");
	str_gets(temp,SLEN);
	pst->lname = (char *)malloc(strlen(temp) + 1);
	strcpy(pst->lname,temp);

}

void makeInfo2(struct namect2 *pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showInfo2(const struct namect2 *pst)
{
	printf("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letters);
}

void cleanUp(struct namect2 *pst)
{
	free(pst->fname);
	free(pst->lname);
}

/*flexMember()--伸缩型数组成员*/
struct flex{
	size_t count;
	float average;
	float scores[];
};

void showFlex(const struct flex *);

void flexMember(void)
{
	struct flex *p1,*p2;

	int n = 5;
	int i = 0;
	float total = 0;

	p1 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(float));
	p1->count = n;
	for(i; i < n; i++)
	{
		p1->scores[i] = 20.0 - i;
		total += p1->scores[i];
	}
	p1->average = total/n;
	showFlex(p1);

	n = 9;
	total = 0;
	p2 = (struct flex *)malloc(sizeof(struct flex) + n * sizeof(float));
	p2->count = n;
	for(i = 0; i < n; i++)
	{
		p2->scores[i] = 20.0 - i;
		total += p2->scores[i];
	}
	p2->average = total/n;
	showFlex(p2);
	free(p1);
	free(p2);

}

void showFlex(const struct flex * p)
{
	int i;
	printf("Scores:\n");
	for(i = 0; i < p->count; i++)
	{
		printf("%f   ", p->scores[i]);
	}
	printf("\nAverage: %.2f\n", p->average);
}

/*bookSaveOnFile()--在文件中保存结构的内容*/
void bookSaveOnFile(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index,filecount;
	FILE *pbooks;
	int size = sizeof(struct book);

	if((pbooks = fopen("C:/Users/xwoof/Desktop/book.dat","a+b")) == NULL)
	{
		fprintf(stderr,"can't open book.dat file\n");
		exit(1);
	}

	rewind(pbooks);
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
		{
			puts("Current contents of book.dat");
		}
		printf("%s by %s : $ %.2f\n", library[count].title,
			library[count].author, library[count].price);
		count++;
	}

	filecount = count;
	if(count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}

	puts("Please add new book title:");
	puts("Press [Enter] at the start of a line to stop.");
	while(count < MAXBKS && str_gets(library[count].title, MAXTITL) != NULL 
		&& library[count].title[0] != '\0')
	{
		puts("Now enter the author;");
		str_gets(library[count].author, MAXAUTL);
		puts("Then enter the price of book:");
		scanf("%f", &library[count++].price);
		while(getchar() != '\n')
			continue;
		if(count < MAXBKS)
			puts("Enter the next book title:");
	}

	if(count > 0)
	{
		puts("Here is the list of your books:");
		for(index = 0; index < count; index++)
		{
			printf("%s by %s : $ %.2f\n", library[index].title,
			library[index].author, library[index].price);
		}
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}

	else
		puts("No books? So bad.\n");

	puts("Bye.");
	fclose(pbooks);

}