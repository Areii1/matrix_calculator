#include <stdio.h>
#include <stdlib.h>

int build_matrix(int rows, int columns);
// void print_matrix(int *, int rows, int columns);

int main(void)
{
	int rows, columns;

	printf("give number of rows\n");
	scanf("%d", &rows);

	printf("give number of columns\n");
	scanf("%d", &columns);

	printf("preferred matrix: %dx%d\n", rows, columns);

	build_matrix(rows, columns);

	return 0;
}

int build_matrix(int rows, int columns)
{
	int matrix[rows][columns];

	int x, y;

	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
			{
			printf("give y = %d, x = %d, entry\n", y, x);
			scanf("%d", &matrix[y][x]);
			printf("got value = %d\n", matrix[y][x]);
			}
	}

	printf("-----------   AFTER VALUE  ASSINGMENTS   ----------\n");

	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
			printf("matrix[%d][%d] = %d\n", y, x, matrix[y][x]);
		}
	}


	return 0;
}



/*
void print_matrix(int *matrix, int rows, int columns)
{
	int y, x;
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
			printf("matrix[y][x] = %d\n", matrix[y][x]);
		}
	}
}
*/










