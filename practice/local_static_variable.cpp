//local_static_variable.cpp -- 使用局部静态变量
#include <stdio.h>
void variablePrint(void);

int useLocalStatic(void)
{
	int count;

	for (count = 0; count <  2;count ++)
		variablePrint();

	return 0;
}

void variablePrint(void)
{
	int fate = 1;
	static int fit = 1;
    
	printf("fate = %d, fit = %d\n", fate++, fit++);
}
