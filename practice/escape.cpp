/*escape.cpp -- ת�����е�ʹ��*/
#include  <stdio.h>

int escape(void)
{
	float salary;

	/*����һ�����棬Ȼ���ӡ�������ݣ�Enter your desired monthly salary:*/
	printf("\aEnter your desired monthly salary:");

	/*��һ�񣬽��������ݣ�Ȼ�����������߸�*/
	printf(" $_______\b\b\b\b\b\b\b");

	scanf("%f",&salary);//�Ӽ��̻�ȡsalary������ֵ

	/*���У�ˮƽ�Ʊ��ʹ����������е���һ���Ʊ�㣬�����Ӧ��ֵ�Լ�����*/
	printf("\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);

	/*��\r��ʼ�������������ǰ����ʼ������ӡGee!,����\nʹ���������һ����ʼ��*/
	printf("\rGee!\n");

	return 0;
}