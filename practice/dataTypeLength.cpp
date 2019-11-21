/*dataTypeLength.cpp -- 不同数据类型在计算机中占用的存储空间大小*/
#include <stdio.h>

void dataTypeLength(void)
{
	printf("Type int has a size of %d bytes.\n", sizeof(int));
	printf("Type short has a size of %d bytes.\n", sizeof(short));
	printf("Type char has a size of %d bytes.\n", sizeof(char));
	printf("Type long has a size of %d bytes.\n", sizeof(long));
	printf("Type float has a size of %d bytes.\n", sizeof(float));
	printf("Type double has a size of %d bytes.\n", sizeof(double));
	printf("Type long long has a size of %d bytes.\n", sizeof(long long));
	printf("Type unsigned int has a size of %d bytes.\n", sizeof(unsigned int));
	printf("Type long double has a size of %d bytes.\n", sizeof(long double));
}