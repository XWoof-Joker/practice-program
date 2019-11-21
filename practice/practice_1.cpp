#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "inttypes.h"
#include "testEventCode.h"
#include "queue.h"
#define LEN 40
#define SQUARE(x) ((x)*(x))

using namespace	std;	

int min(int a, int b );


int main(int argc,char *argv[])
{
	//badParameterCount();
	//dataTypeLength();
	//escape();
	//storeString();
    //wheat();
    //modulo_calculate();
    //sum();
	//multiplication();
	//pointer_operat();
	//pointer_2dArray();
	//funcOfDeal2DArray();
	//exercise();
	//Create2dDynamicArray();
	//Create1dDynamicArray();
	//getsPuts();
	//fgets1();
	//fgets2();
	//fgets3();
	//cut_string_length();
	//str_cat();
	//strcat_checkLen();
	//string_copy();
	//file_fopen();
	//array2d();
	//sortTest();
	//structManyBook();
	//funds();
	//funds2();
	//names1();
	//names2();
    //names3();
	//flexMember();
	//bookSaveOnFile();
	//func_pointer();
	//linkListOfFilm();
	//film3();
	//useTreeToStorePet();
	//UseStack();
	//fseekExample();
	//sort_string();
	//ifdef();
	//useLocalStatic();

	const char *fmt = "X is %d.\n";
    

	
	
	/*char ch;
	int count = 0;
	while((ch = getchar()) != '#')
	{
		if(ch == '\n')
			continue;
		while(getchar() != '\n')
			continue;
		putchar(ch);
		printf("\n");
	}*/
	

	/*  编写函数使用指针，交换两数的值    */
	//int a = 3, b = 4;
	//changeValue(&a,&b);
	//printf("%d %d\n",a, b);

    

	//int a = 1;
	//int b = 2;
 //   const int * p = &a;//指向常量的指针，不能通过指针修改常指针指向的值
	//p = &b;//p可以在任意时候重新赋值一个新内存地址
	//b = 4;//此处不可以用*p来代替
	//printf("%d\n", p[0]);


	//FILE *in, *out;
	//int ch;
	//char name[LEN];
	//int count = 0;

	////检查命令行参数
	//if(argc < 2){
	//
	//	fprintf(stderr, "Usage: %s filename\n", argv[0]);
	//	exit(EXIT_FAILURE);
	//}
	////设置输入
	//if((in = fopen(argv[1], "r")) == NULL){
	//
	//	fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
	//	exit(EXIT_FAILURE);
	//}
	////设置输出
	//strncpy(name, argv[1], LEN - 5);
	//name[LEN - 5] = '\0';
	//strcat(name, ".txt");
	//if((out = fopen(name, "w")) == NULL){
	//
	//	fprintf(stderr, "Can't create out put file.\n");
	//	exit(3);
	//}
	////拷贝数据
	//while((ch = getc(in)) != EOF){
	//
	//	printf("%d ",ch);
	//	if(count++ % 3 == 0)
	//		putc(ch, out);
	//		
	//}
	//if(fclose(in) != 0 || fclose(out) != 0){
	//
	//	fprintf(stderr, "Error in closing files.\n");
	//}

	
	



	return 0;
}

	