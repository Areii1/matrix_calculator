#include <stdio.h>
#include <stdlib.h>

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);
// int copy_matrix(int *destination_matrix, int *source_matrix);

int main(void)
{
	int first_rows, first_columns, i;
	int **first_matrix;

	printf("provide information for the first matrix\n");
	printf("give number of rows\n");
	scanf("%d", &first_rows);

	printf("give number of columns\n");
	scanf("%d", &first_columns);

	printf("preferred matrix: %dx%d\n", first_rows, first_columns);
	
	first_matrix = malloc(first_rows * sizeof *first_matrix);
	for (i = 0; i < first_rows; i++)
	{
		first_matrix[i] = malloc(first_columns * sizeof *first_matrix[i]);
	}

	build_matrix(first_matrix, first_rows, first_columns);
	print_matrix(first_matrix, first_rows, first_columns);

//----------------------- SECOND MATRIX -----------------------
	int second_rows, second_columns, j;
	int **second_matrix;

	printf("provide information for the second matrix\n");
	printf("give number of rows\n");
	scanf("%d", &second_rows);

	printf("give number of columns\n");
	scanf("%d", &second_columns);

	printf("preferred matrix: %dx%d\n", second_rows, second_columns);
	
	second_matrix = malloc(second_rows * sizeof *second_matrix);
	for (j = 0; j < second_rows; j++)
	{
		second_matrix[j] = malloc(second_columns * sizeof *second_matrix[i]);
	}

	build_matrix(second_matrix, second_rows, second_columns);
	print_matrix(second_matrix, second_rows, second_columns);

	for (i = 0; i < first_rows; i++)
	{
		free(first_matrix[i]);
	}

	free(first_matrix);

	for (j = 0; j < second_rows; j++)
	{
		free(second_matrix[j]);
	}

	free(second_matrix);

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

	return 0;
}

void print_matrix(int* matrix[], int rows, int columns)
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









