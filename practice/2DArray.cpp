/*--处理二维数组的函数*/
#include <stdio.h>
int sum(const int ar[], int n);

int funcOfDeal2DArray(void)
{
	int b[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int i;
	int total = 0;

	for (i = 0; i < 3; i++)
	{
		total += sum(b[i], 4);
	}

	printf("total = %d\n", total);

	
	return 0;
}

int sum(const int ar[], int n)
{
	int total = 0;

	for (int i =0; i < n; i++)
	{
		total += ar[i]; 
	}

	return total;
}

/*处理二维数组的函数*/
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);//计算二维数组各行之和
void sum_cols(int [][COLS], int rows);//计算二维数组各列之和
int sum2dArray(int (*ar)[COLS], int rows);//计算二维数组所有元素之和

int array2d(void){
	
	int junk[ROWS][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	/*打印二维数组*/
	printf("junk[%d][%d] = {\n", ROWS, COLS);
	for(int r = 0; r < ROWS; r++){
	
		printf("{");
		for(int c = 0; c < COLS; c++){
			
			if(c == (COLS - 1))
				printf("%d", junk[r][c]);
			else
				printf("%d,", junk[r][c]);
		}
		if(r == (ROWS - 1))
			printf("}\n");
		else
			printf("},\n");
	}
	printf("};\n\n");

	sum_rows(junk, ROWS);
	printf("\n");
	sum_cols(junk, ROWS);

	printf("Sum of all elements = %d\n", sum2dArray(junk, ROWS));

	return 0;

}

void sum_rows(int ar[][COLS], int rows){

	int r,c;
	int total = 0;

	for(r = 0; r < rows; r++){
	
		for(c = 0; c < COLS; c++){
		
			total += ar[r][c];
		}

		printf("row %d : sum = %d\n", r, total);

		total = 0;
	}
	
	
}

void sum_cols(int ar[][COLS], int rows){

	int r,c;
	int total = 0;

	for(c = 0; c < COLS; c++){
	
		for(r = 0; r < rows; r++){
		
			total += ar[r][c];
		}

		printf("col %d : sum = %d\n", c, total);
		total = 0;
	}

}

int sum2dArray(int (*ar)[COLS], int rows){

	int r,c;
	int total = 0;

	for(r = 0; r < rows; r++){
	
		for(c = 0; c < COLS; c++){
		
			total += ar[r][c];
		}
	}

	return total;
}

