#include <stdio.h>
#include "sortAlgorithm.h"

void sortTest(){

	int a[11] = {10, 6, 11, 5, 12, 7, 4, 10, 13, 2, 1};
	//int a[11] = {1, 2, 3, 4, 5, 22, 7, 8, 9, 10, 11};
	//int a[4] = {1,3,2,4};
	int length = sizeof(a)/sizeof(a[0]);
	int i,b[11];
	//bubble_sort(a, length);
	//selection_sort(a, length);
	//insertion_sort(a, length);
	//shell_sort(a, length);
	//MergeSort(a, b, 0, 10);
	quick_sort(a,0,length - 1);
	for(i = 0; i < length; i++){
	
		printf("%d ", a[i]);
	}
	printf("\n");

}