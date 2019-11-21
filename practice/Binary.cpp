/* Binary.cpp -- 将整数转化为二进制输出 */
#include <stdio.h>
void to_Binary(unsigned long n)
{
	int a;
	a = n % 2;
	if(n >= 2)
	{
		to_Binary(n/2);
	}
	printf("%d", a);
}