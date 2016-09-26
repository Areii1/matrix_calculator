#include <stdio.h>
#include <stdlib.h>

// int[][] get_a_matrix(int rows, int columns);

int main(void)
{
	int rows, columns;

	printf("give number of rows\n");
	scanf("%d", &rows);

	printf("give number of columns\n");
	scanf("%d", &columns);

	printf("preferred matrix: %dx%d\n", rows, columns);

	return 0;
}
