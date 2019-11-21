#include <stdio.h>
#include "malloc.h"
/*���ֳ����������㷨*/

/*ð������*/
/*����ԭ��
��ԱȽ����ڵĵ��������ݣ���һ����ǰһ��С���������ǣ�ֱ�����һ�ԣ���һ��������ɣ�����Ԫ��ɸѡ����
����������棻����ִ��ͬ���Ĳ���n-2�ˣ����ɽ����ݰ���С��������
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

/*ѡ������*/
/*------------����ԭ��-----------------*/
/*������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�Ȼ���ٴ�ʣ��δ����
Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ��������*/
int selection_sort(int a[], int length){

	int temp,i,j;
	
	for (i = 0; i < length - 1; i++){
		
		int minIndex = i;//�趨��Сֵ����
		for( j = i+1; j < length; j++){	
			
			if(a[j] < a[minIndex])
				minIndex = j;//Ѱ����Сֵ���ҵ���ǰ��Сֵ�����������	
		}
		//���ҵ�����Сֵ����������һ��Ԫ�ؽ���
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

/*��������*/
int insertion_sort(int a[], int length){

	int i,j,current;

	for (i = 1;i < length; i++){
	
		current = a[i];
		/*ʹ��whileѭ��ʵ�ֺ�������*/
		int preIndex = i - 1;
		while (preIndex >= 0 && a[preIndex] > current){
		
			a[preIndex + 1] = a[preIndex];
			preIndex--;
		}
		a[preIndex + 1] = current;
		/*ʹ��forѭ��ʵ�ֺ�������*/
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

/*ϣ������*/
/*�򵥲�������ĸĽ��档�����������Ĳ�֮ͬ�����ڣ��������ȱȽϾ����Զ��Ԫ�ء�ϣ�������ֽ���С��������*/
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

/*�鲢����*/
/*�鲢����*/
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
 
//�ڲ�ʹ�õݹ齫����ΪN�����з�Ϊ���ɸ�������
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//�������int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

/*��������*/
int quick_sort(int a[], int startIndex, int endIndex){

	if(startIndex < endIndex){//�ݹ������������
	
		int i,j,temp;
		//���������ֱ�ָ��ͷ�ͽ�β������
		i = startIndex;
		j = endIndex;
		int key = a[endIndex];//���������һ��Ԫ����Ϊ�ؼ�ֵ
		while(i <= endIndex && j >= startIndex){
			while(a[j] >= key && i != j)//�Ӻ���ǰɨ�裬�ҵ�һ��С�ڹؼ�ֵ������
				j--;
			while(a[i] <= key && i != j )//��ǰ����ɨ�裬�ҵ�һ�����ڹؼ�ֵ������
				i++;
			if(i == j)//��i����jʱ��˵���ѽ��������ߵ�ֵ�Ѿ�û�п��Խ����ģ��˳�ѭ��
				break;
			//���ҵ���һ��С�ڹؼ�ֵ������a[j]��һ�����ڹؼ�ֵ������a[i]����
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
		//���ؼ�ֵ�ŵ��м䣬ʹС�ڹؼ�ֵ�����ݾ�λ������ߣ����ڹؼ�ֵ�����ݾ�λ�����ұ�
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

		quick_sort(a,0,i);//һ�����������ʹ�õݹ�ķ�ʽ�����Թؼ�ֵ��ߵ����ݽ��п�������
		quick_sort(a,j,endIndex);//һ�����������ʹ�õݹ�ķ�ʽ�����Թؼ�ֵ�ұߵ����ݽ��п�������

	}

	return 0;
}
