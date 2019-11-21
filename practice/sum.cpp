#include <stdio.h>

int sum(void)
{
	long num;
	long sum = 0L;

	printf("Please enter a integer to be summed (q to quit):\n ");//先提示用户输入一个数字

	while(scanf("%d", &num) == 1)//将从键盘获取字符函数返回值作为判断条件，获取的结果为数字，则执行累加
	{
		sum = sum + num;
		printf("Please enter next number(q to quit):");//继续提示用户输入数字
		
	}
	printf("Those integers sum to %ld.\n", sum);//打印最后的累加结果

	return 0;
}