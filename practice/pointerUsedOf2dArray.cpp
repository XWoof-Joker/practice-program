#include <stdio.h>

void pointer_2dArray(void)
{
	int a[4][2] = { {2,4}, {1,8}, {6,3}, {5,7} };
	int (*p)[2];
	int **pt;

	p = a;

	printf("   p = %p,    p + 1 = %p\n", p, p + 1);
	printf("p[0] = %p, p[0] + 1 = %p\n", p[0], p[0] + 1);
	printf("  *p = %p,   *p + 1 = %p\n", *p, *p + 1);
	printf("        p[0][0] = %d\n", p[0][0]);
	printf("          *p[0] = %d\n", *p[0]);
	printf("            **p = %d\n", **p);
	printf("        p[2][1] = %d\n",p[2][1]);
	printf("*(*(p + 2) + 1) = %d\n", *(*(p + 2) + 1));







}