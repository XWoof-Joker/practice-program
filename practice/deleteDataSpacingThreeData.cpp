#include <stdio.h>
#include "queue.h"

void deleteData(){

	Queue Q;
	int n;
	InitQueue(&Q);

	printf("输入一组整数，程序会每隔三个数删除一个数，");
	printf("到结尾时回到开头，继续执行该操作，直到剩下最后一个数：\n");

	while(scanf("%d ",&n) == 1)
	{		
		EnQueue(&Q, n);//将上面从键盘获取的一组整存到队列中
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