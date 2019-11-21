/*--二维数组与指针，地址的关系*/
#include <stdio.h>

void access2DArrayByAddress()
{
	int a[4][2] = { {1,2}, {3,4}, {5,6}, {7,8} };

	printf("   a = %p,     a + 1 = %p\n", a, a + 1 );
	printf("a[0] = %p, &a[0] + 1 = %p\n", a[0], &a[0] + 1 );
	printf("                a[1] = %p\n", a[1]);
	printf("a[3] = %p\n", a[3]);
	printf("  *a = %p,  *(*a + 2) = %d\n", *a, *(*a + 2));
	printf("&a[0][0] = %p\n", &a[0][0]);
	printf("a[0][0] = %d\n", a[0][0]);
	printf("  *a[0] = %d\n", *a[0]);
	printf("    **a = %d\n", **a);
	printf("        a[3][1] = %d\n", a[3][1]);
	printf("*(*(a + 3) + 1) = %d\n", *(*(a +3) + 1));
	
	//int b[3] = {2,3,4};
	//printf(" b = %p\n", b);
	//printf("&b = %p\n", &b);



}