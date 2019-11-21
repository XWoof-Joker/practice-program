#include <stdio.h>

void pointer_operat(void)
{
	int a[5] = {100, 200, 300, 400, 500};
	int * pointer1, * pointer2, * pointer3;

	pointer1 = a;
	pointer2 = &a[2];

	printf("pointer value, deferenced pointer, pointer address:\n");
	printf("pointer1 = %p, *pointer1 = %d, &pointer1 = %p\n", pointer1, *pointer1, &pointer1);

	//指针加法
	pointer3 = pointer1 + 3;
	printf("\n");
	printf("adding an int to a pointer:\n");
	printf("pointer1 + 3 = %p, *(pointer1 + 3) = %d\n", pointer3, *pointer3);
    
	//递增指针
	pointer1++;
	printf("\nvalues after pointer1++:\n");	
	printf("pointer1 = %p, *pointer1 = %d, &pointer1 = %p\n", pointer1, *pointer1, &pointer1);	
	
	//递减指针
	pointer2--;
	printf("\nvalues after pointer2--:\n");	
	printf("pointer2 = %p, *pointer2 = %d, &pointer2 = %p\n", pointer2, *pointer2, &pointer2);

	--pointer1;//恢复为初始值
	++pointer2;//恢复为初始值
	printf("\nPointer reset to original values:\n");
	printf("pointer1 = %p, pointer2 = %p\n", pointer1, pointer2);
	
	//一个指针减去另一个指针
	printf("\nSubtracting one pointer from another:\n");
	printf("pointer1 = %p, pointer2 = %p, pointer2 - pointer1 = %d\n", pointer1, pointer2, pointer2 - pointer1);

	//一个指针减去一个整数
	printf("\nSubtracting an int from a pointer:\n");
	printf("pointer3 = %p, pointer3 - 2 = %p\n", pointer3, pointer3 - 2);

	
}