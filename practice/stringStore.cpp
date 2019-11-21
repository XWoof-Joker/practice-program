#include <stdio.h>
#include <string.h>
#define DENSITY 62.4 //人体密度（单位：镑/立方英尺）

int storeString(void)
{
	float weight, volume;
	int size, letters;
	char name[40];

	printf("What's your first name?\n");
	scanf("%s", name);
	printf("%s, what's your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof(name);
	letters = strlen(name);
	volume = weight / DENSITY;
    printf("well, %s, your volume is %2.2f cubic feet.\n", name, volume);
	printf("Also, your first name has %d letters,\n", letters);
	printf("and we have %d bytes to store it.\n", size);

	return 0;
}