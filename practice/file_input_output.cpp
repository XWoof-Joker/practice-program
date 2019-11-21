#include <stdio.h>
#include <stdlib.h>
#define FILEPATH "C:/Users/xwoof/Desktop/2.txt"

int file_fopen(){

	int ch;
	FILE *fp;
	unsigned long count = 0;
	/*if (argc != 2 ){
	
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}*/
	if ((fp = fopen("C:/Users/xwoof/Desktop/1.txt", "r")) == NULL){
	
		printf("Can't open %s\n", "C:/Users/xwoof/Desktop/1.txt");
		exit(EXIT_FAILURE);
	}

	FILE *fp2 = fopen(FILEPATH, "w");

	while ((ch = getc(fp)) != EOF){
	
		putc(ch, fp2);//写到文件中
		putc(ch, stdout);//与putchar(ch);相同
		count++;
	} 
	printf("\n");
	if (fclose(fp) != 0)
		printf("Error in closing file %s\n","C:/Users/xwoof/Desktop/1.txt");
	/*if (fclose(fp2) != 0)
		printf("Error in closing file %s\n",FILEPATH);*/
	printf("File %s has %lu characters\n", "C:/Users/xwoof/Desktop/1.txt", count);

	return 0;
	
}