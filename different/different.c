#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	long *differences;
	differences = (long*)malloc(sizeof(long));
	long x, y;
	int counter = 0;
	while (scanf("%ld %ld", &x, &y) != EOF)
	{
		differences[counter] = (long)malloc(sizeof(long));
		differences[counter] =  labs(x-y);
		counter++;
	}

	for (int i = 0; i < counter; i++)
		printf("%ld\n", differences[i]);
}