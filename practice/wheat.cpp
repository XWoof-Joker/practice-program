/*wheat.cpp -- 指数增长*/
#include <stdio.h>
#define SQUARES 64           //棋盘的方格数

int wheat(void)
{
	const double CROP = 2e16;//小麦年产量（单位：粒数）
	int count = 1;//定义棋盘方格计数
	double total = 1, 
		   grid_Grains = 1;//定义总数以及每个棋盘格子小麦粒数

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