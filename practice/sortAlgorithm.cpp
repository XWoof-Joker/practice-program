#include <stdio.h>
#include "malloc.h"
/*几种常见的排序算法*/

/*冒泡排序*/
/*工作原理：
逐对比较相邻的的两个数据，后一个比前一个小，交换他们，直到最后一对，第一趟排序完成，最大的元素筛选出来
储存在最后面；继续执行同样的操作n-2趟，最后可将数据按从小到大排序
*/
int bubble_sort(int a[], int length) {

	int i, j, temp;

	for (i = 0; i < length - 1; i++){

		for(j = 0; j < length - 1 - i;j++){
			
			if (a[j] > a[j+1]){
			
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

			}
			
		}
	}

	for (i = 0; i < length; i++){
	
		printf("%d ", a[i]);
	}

	return 0;

}

/*选择排序*/
/*------------工作原理-----------------*/
/*首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序
元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕*/
int selection_sort(int a[], int length){

	int temp,i,j;
	
	for (i = 0; i < length - 1; i++){
		
		int minIndex = i;//设定最小值索引
		for( j = i+1; j < length; j++){	
			
			if(a[j] < a[minIndex])
				minIndex = j;//寻找最小值，找到当前最小值，将索引变更	
		}
		//将找到的最小值与无序区第一个元素交换
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}

	for(i = 0; i < length; i++){
	
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}

/*插入排序*/
int insertion_sort(int a[], int length){

	int i,j,current;

	for (i = 1;i < length; i++){
	
		current = a[i];
		/*使用while循环实现后移数据*/
		int preIndex = i - 1;
		while (preIndex >= 0 && a[preIndex] > current){
		
			a[preIndex + 1] = a[preIndex];
			preIndex--;
		}
		a[preIndex + 1] = current;
		/*使用for循环实现后移数据*/
		/*for (j = i-1; j >=0; j--){
		
			if (a[j] > current)	
				a[j+1] = a[j];
			else
				break;
		}
		a[j+1] = current;*/
	}

	for(i = 0; i < length; i++){
	
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

/*希尔排序*/
/*简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。*/
int shell_sort(int a[], int length){

	int gap;
	int i,j;
	for (gap = length/2; gap >= 1; gap /= 2){
	
		for (i = 0; i < gap; i++){
		
			for(j = i+gap; j < length; j +=gap){
			
				int preIndex = j-gap;
				int current = a[j];
				while (preIndex >= 0 && a[preIndex] > current ){
				
					a[preIndex+gap] = a[preIndex];
					preIndex -= gap;
				}
				a[preIndex+gap] = current;
			}
		}
	}

	for(i = 0; i < length; i++){
	
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

/*归并排序*/
/*归并操作*/
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归将长度为N的序列分为若干个子序列
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

/*快速排序*/
int quick_sort(int a[], int startIndex, int endIndex){

	if(startIndex < endIndex){//递归结束与否的条件
	
		int i,j,temp;
		//设置两个分别指向开头和结尾的索引
		i = startIndex;
		j = endIndex;
		int key = a[endIndex];//将数组最后一个元素作为关键值
		while(i <= endIndex && j >= startIndex){
			while(a[j] >= key && i != j)//从后往前扫描，找到一个小于关键值的数据
				j--;
			while(a[i] <= key && i != j )//从前往后扫描，找到一个大于关键值的数据
				i++;
			if(i == j)//当i等于j时，说明已将左右两边的值已经没有可以交换的，退出循环
				break;
			//将找到的一个小于关键值的数据a[j]和一个大于关键值的数据a[i]交换
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		//将关键值放到中间，使小于关键值的数据均位于其左边，大于关键值的数据均位于其右边
		if(j == startIndex && a[j] > a[endIndex] ){
			temp = a[endIndex];
			a[endIndex] = a[j];
			a[j] = temp;
			j++;
		}
		else{	
			j++;
			temp = a[endIndex];
			a[endIndex] = a[j];
			a[j] = temp;
		}

		quick_sort(a,0,i);//一趟排序结束，使用递归的方式继续对关键值左边的数据进行快速排序
		quick_sort(a,j,endIndex);//一趟排序结束，使用递归的方式继续对关键值右边的数据进行快速排序

	}

	return 0;
}
