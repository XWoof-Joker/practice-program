#include <iostream>

using namespace std;

void VLA(void){
	
	/*һά��̬���鶨�壬C++��ʽ*/
	int n;
	
	cout << "����������ĳ���" << endl;
	cin >> n;

    int *ar = new int[n];

	cout << "�����������Ԫ�أ�����Ϊ���鳤�ȵĸ���" << endl;

	for(int i = 0; i < n; i++){
	
		cin >> ar[i];
		cout << ar[i] <<" ";
	}
	
	
	

	


}

/*ʹ��C�ķ�ʽ����һά��̬����*/
void Create1dDynamicArray(){

	int m;
	int i;
	
	printf("������Ҫ������һά��̬����ĳ��ȣ�\n");
	scanf("%d",&m);

	int *p = (int *)malloc(sizeof(int)*m);//malloc����Ϊ��̬�����ڴ溯��������memory allocation���ú�������void��ָ�룬��Ҫʱ���������ת��
	//sizeof(int)*m�е�*�ǳ˺ţ���ʾ����m��int�������ʹ�С�Ĵ洢�ռ�

	printf("������һά����Ҫ�洢�����ݣ�\n");

	for(i = 0; i < m; i++){
	
		scanf("%d", &p[i]);
	}

	printf("������ݣ�\n");

	for(i = 0; i < m; i++){
	
		printf("%d ", p[i]);
	}

	free(p);
}

/*ʹ��C�ķ�ʽ���嶯̬��ά����*/
void Create2dDynamicArray(){

	/*ʹ�ö���ָ��ʵ��*/
	int m,n;
	int i,j;
	int **p;
 
    printf("�����������к��У�");
	scanf("%d%d",&m,&n);
 

	p = (int **)malloc(sizeof(int*)*m); //������,ʵ�����Ǵ�����һ����ָ���������̬�ڴ棬
										//���ڴ����ָ�롣�������Ϊ����һ��һάָ������
	
	for(i = 0; i < m; i++)
	{
		*(p+i) = (int *)malloc(sizeof(int)*n);//�����С�ʵ�����Ǵ���N��int���ʹ�С���ڴ棬
		                                      //Ȼ�󽫴������ڴ��׵�ַ���������ʼ�����洴����ָ�������Ԫ��
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

	//�ͷſ��ٵĶ�ά�ռ�
	for(i = 0; i < m;i++)
		free(*(p+i));

	free(p);

}