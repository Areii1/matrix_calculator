#include <stdio.h>
#include <stdlib.h>

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);
void add_matrices(int* A[], int* B[], int* destination[]);
void substract_matrices(int* A[], int* B[], int* destination[]);
// int copy_matrix(int *destination_matrix, int *source_matrix);

#define MAX_ROWS 5
#define MAX_COLUMNS 5

int main(void)
{
	// ------------------------- FIRST MATRIX ---------------------------
	int first_rows, first_columns, i;
	int **first_matrix;

	// probe for measures
	printf("give information for the first matrix\n");
	printf("give number of rows\n");
	scanf("%d", &first_rows);
	printf("give number of columns\n");
	scanf("%d", &first_columns);
	printf("preferred matrix: %dx%d\n\n\n", first_rows, first_columns);
	
	//allocate first matrix (2-d int array)
	first_matrix = malloc(MAX_ROWS * sizeof *first_matrix);
	for (i = 0; i < MAX_ROWS; i++)
	{
		first_matrix[i] = malloc(MAX_COLUMNS * sizeof *first_matrix[i]);
	}

	//pass allocated matrix for element probing
	build_matrix(first_matrix, first_rows, first_columns);
	printf("-------------------- FIRST MATRIX -------------------\n");
	print_matrix(first_matrix, first_rows, first_columns);
	printf("-----------------------------------------------------\n");

//----------------------- SECOND MATRIX -----------------------
	int second_rows, second_columns, j;
	int **second_matrix;

	//probe for measures
	printf("provide information for the second matrix\n");
	printf("give number of rows\n");
	scanf("%d", &second_rows);
	printf("give number of columns\n");
	scanf("%d", &second_columns);
	printf("preferred matrix: %dx%d\n\n\n", second_rows, second_columns);
	
	//allocate second matrix (2-d int array)
	second_matrix = malloc(MAX_ROWS * sizeof *second_matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		second_matrix[j] = malloc(MAX_COLUMNS * sizeof *second_matrix[i]);
	}

	//pass allocated matrix for element probing
	build_matrix(second_matrix, second_rows, second_columns);
	printf("-------------------- SECOND MATRIX -------------------\n");
	print_matrix(second_matrix, second_rows, second_columns);
	printf("------------------------------------------------------\n");

	int **destination_matrix;

	//allocate destination matrix (2-d int array)
	destination_matrix = malloc(MAX_ROWS * sizeof *destination_matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		destination_matrix[j] = malloc(MAX_COLUMNS * sizeof *destination_matrix[i]);
	}

	if (first_rows == second_rows && first_columns == second_columns)
	{
		substract_matrices(first_matrix, second_matrix, destination_matrix);
	}
	
	printf("-------------------- DESTINATION MATRIX -------------------\n");
	print_matrix(destination_matrix, first_rows, first_columns);
	printf("-----------------------------------------------------------\n");

	// free unused matrix space
	for (i = 0; i < MAX_ROWS; i++)
	{
		free(first_matrix[i]);
		free(second_matrix[i]);
		free(destination_matrix[i]);
	}

	free(first_matrix);
	free(second_matrix);
	free(destination_matrix);
	
	return 0;
}


int build_matrix(int* matrix[], int rows, int columns)
{

	int x, y;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < columns; x++)
		{
			if ((y >= rows && y < MAX_ROWS) || (x >= columns && x < MAX_COLUMNS))
			{
				matrix[y][x] = 0;
			}
			else
			{
				printf("give [%d,%d] element:\n", y, x);
				scanf("%d", &matrix[y][x]);
			}
		}
	}

	return 0;
}

void print_matrix(int* matrix[], int rows, int columns)
{
	int y, x;	
	
	for (y = 0; y < MAX_ROWS; y++)
	{
		printf("\n");

		for (x = 0; x < MAX_COLUMNS; x++)
		{
			if (x == columns)
			{
				printf("\t");
			}

			printf("%d\t", matrix[y][x]);
		}

		printf("\n");
	}
}

void add_matrices(int* A[], int* B[], int* destination[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			destination[y][x] = A[y][x] + B[y][x];
		}
	}
}

void substract_matrices(int* A[], int* B[], int* destination[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			B[y][x] = B[y][x] * -1;
			destination[y][x] = A[y][x] + B[y][x];
		}
	}

}





