#include <stdio.h>

int sum(void)
{
	long num;
	long sum = 0L;

	printf("Please enter a integer to be summed (q to quit):\n ");//����ʾ�û�����һ������

	while(scanf("%d", &num) == 1)//���Ӽ��̻�ȡ�ַ���������ֵ��Ϊ�ж���������ȡ�Ľ��Ϊ���֣���ִ���ۼ�
	{
		sum = sum + num;
		printf("Please enter next number(q to quit):");//������ʾ�û���������
		
	}
	printf("Those integers sum to %ld.\n", sum);//��ӡ�����ۼӽ��

	return 0;
}