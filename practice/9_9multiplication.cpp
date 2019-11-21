#include <stdio.h>


int multiplication(void)
{
	int c_num, r_num;
	for(c_num = 1; c_num < 10; c_num++)
	{
		for(r_num  =1; r_num <= c_num; r_num++)
		{
			printf("%d X %d = %d    ",r_num, c_num, r_num * c_num);
		}
		printf("\n");
	}
	return 0;
}