#include <stdio.h>
#include <stdlib.h>

int build_matrix(int* matrix[], int rows, int columns);
// void print_matrix(int** matrix, int rows, int columns);
// int copy_matrix(int *destination_matrix, int *source_matrix);

int main(void)
{
	int rows, columns, i;
	int **first_matrix;

	printf("give number of rows\n");
	scanf("%d", &rows);

	printf("give number of columns\n");
	scanf("%d", &columns);

	printf("preferred matrix: %dx%d\n", rows, columns);
	
	first_matrix = malloc(rows * sizeof *first_matrix);
	for (i = 0; i < rows; i++)
	{
		first_matrix[i] = malloc(columns * sizeof *first_matrix[i]);
	}

	build_matrix(first_matrix, rows, columns);

	for (i = 0; i < rows; i++)
	{
		free(first_matrix[i]);
	}

	free(first_matrix);
	// print_matrix(*matrix, rows, columns);

	return 0;
}


int build_matrix(int* matrix[], int rows, int columns)
{

	int x, y;

	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
			{
			printf("give [%d,%d] element:\n", y, x);
			scanf("%d", &matrix[y][x]);
			printf("got value %d\n", matrix[y][x]);
			}
	}

	printf("-----------   AFTER VALUE  ASSINGMENTS   ----------\n");

	for (y = 0; y < rows; y++)
	{
		printf("\n");

		for (x = 0; x < columns; x++)
		{
			printf("%d\t", matrix[y][x]);
		}

		printf("\n");
	}


	return 0;
}

/*
void print_matrix(int *matrix, int rows, int columns)
{
	int y, x;	
	
	for (y = 0; y < rows; y++)
	{
		printf("\n");

		for (x = 0; x < columns; x++)
		{
			printf("%d\t", matrix[y][x]);
		}

		printf("\n");
	}
}
*/









