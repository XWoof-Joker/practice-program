#include <stdio.h>
#include "queue.h"

void deleteData(){

	Queue Q;
	int n;
	InitQueue(&Q);

	printf("����һ�������������ÿ��������ɾ��һ������");
	printf("����βʱ�ص���ͷ������ִ�иò�����ֱ��ʣ�����һ������\n");

	while(scanf("%d ",&n) == 1)
	{		
		EnQueue(&Q, n);//������Ӽ��̻�ȡ��һ�����浽������
	}

	while(QueueLength(Q) != 1)
	{
		for(int i = 0; i < 3; i++)
		{
			EnQueue(&Q,Top(Q));
			DeQueue(&Q);
		}
		DeQueue(&Q);
	}
	PrintQueue(Q);
	
}