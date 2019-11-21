#include <iostream>

using namespace std;

void VLA(void){
	
	/*一维动态数组定义，C++方式*/
	int n;
	
	cout << "请输入数组的长度" << endl;
	cin >> n;

    int *ar = new int[n];

	cout << "请输入数组的元素，个数为数组长度的个数" << endl;

	for(int i = 0; i < n; i++){
	
		cin >> ar[i];
		cout << ar[i] <<" ";
	}
	
	
	

	


}

/*使用C的方式定义一维动态数组*/
void Create1dDynamicArray(){

	int m;
	int i;
	
	printf("请输入要创建的一维动态数组的长度：\n");
	scanf("%d",&m);

	int *p = (int *)malloc(sizeof(int)*m);//malloc函数为动态分配内存函数，即是memory allocation。该函数返回void型指针，必要时需进行类型转换
	//sizeof(int)*m中的*是乘号，表示开辟m个int数据类型大小的存储空间

	printf("请输入一维数组要存储的数据：\n");

	for(i = 0; i < m; i++){
	
		scanf("%d", &p[i]);
	}

	printf("输出数据：\n");

	for(i = 0; i < m; i++){
	
		printf("%d ", p[i]);
	}

	free(p);
}

/*使用C的方式定义动态二维数组*/
void Create2dDynamicArray(){

	/*使用二级指针实现*/
	int m,n;
	int i,j;
	int **p;
 
    printf("请输入数组行和列：");
	scanf("%d%d",&m,&n);
 

	p = (int **)malloc(sizeof(int*)*m); //开辟行,实际上是创建了一块存放指针的连续动态内存，
										//用于存放行指针。可以理解为创建一个一维指针数组
	
	for(i = 0; i < m; i++)
	{
		*(p+i) = (int *)malloc(sizeof(int)*n);//开辟列。实际上是创建N个int类型大小的内存，
		                                      //然后将创建的内存首地址用于逐个初始化上面创建的指针数组的元素
	}

	for(i = 0; i < m; i++){
	
		for(j = 0; j < n; j++){
		
			scanf("%d", &p[i][j]);
		}
	}

	for(i = 0; i < m; i++){
	
		for(j = 0; j < n; j++){
		
			printf("%d   ", p[i][j]);
		}
		printf("\n");
	}

	//释放开辟的二维空间
	for(i = 0; i < m;i++)
		free(*(p+i));

	free(p);

}