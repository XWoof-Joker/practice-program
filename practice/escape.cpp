/*escape.cpp -- 转义序列的使用*/
#include  <stdio.h>

int escape(void)
{
	float salary;

	/*发出一声警告，然后打印如下内容：Enter your desired monthly salary:*/
	printf("\aEnter your desired monthly salary:");

	/*空一格，接上面内容，然后光标向左退七格*/
	printf(" $_______\b\b\b\b\b\b\b");

	scanf("%f",&salary);//从键盘获取salary变量的值

	/*换行，水平制表符使光标移至该行的下一个制表点，输出对应的值以及内容*/
	printf("\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);

	/*以\r开始，将光标移至当前行起始处，打印Gee!,接着\n使光标移至下一行起始处*/
	printf("\rGee!\n");

	return 0;
}