/*wheat.cpp -- ָ������*/
#include <stdio.h>
#define SQUARES 64           //���̵ķ�����

int wheat(void)
{
	const double CROP = 2e16;//С�����������λ��������
	int count = 1;//�������̷������
	double total = 1, 
		   grid_Grains = 1;//���������Լ�ÿ�����̸���С������

	printf("gridNO.      grid Grains      total grains    difference of world\n");
	printf("                              added           grains one year\n");
	
	while(count < SQUARES)
	{
		printf("%4d %17.2e %17.2e %17.2e\n", count, grid_Grains, total, total / CROP);
		count = count++;
		grid_Grains = 2.0 * grid_Grains;
		total = total + grid_Grains;
		
	}

	printf("That's all.\n");

	return 0;

}