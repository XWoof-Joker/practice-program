/*badParameterCount.cpp -- printf函数参数错误的情况*/
#include <stdio.h>

int badParameterCount(void)
{
	int n = 4, m = 5;
	float a = 7.0, b = 8.0;

	printf("%d \n", n, m);
	printf("%d %d %d \n", n);
	printf("%d %d \n", a, b);

	return 0;
	
}