/* Binary.cpp -- ������ת��Ϊ��������� */
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