#include <stdio.h>
#include <stdlib.h>
#include "matrix_algebra.h"

#define MAX_ROWS 5
#define MAX_COLUMNS 5

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);
void ask_for_measures(int a_or_b);
void initialize_matrix(int*** matrix, int a_or_b);
void malloc_matrix(int*** matrix);

int A_rows, A_columns, B_rows, B_columns;
int **A;
int **B;
int **destination_matrix;

int main(void)
{
// ----------------------FIRST MATRIX -------------------------------
	initialize_matrix(&A, 1);
	build_matrix(A, A_rows, A_columns);
	print_matrix(A, A_rows, A_columns);
//-------------------------------------------------------------------

//----------------------- SECOND MATRIX -----------------------------
	initialize_matrix(&B, 2);
	build_matrix(B, B_rows, B_columns);
	print_matrix(B, B_rows, B_columns);
//-------------------------------------------------------------------

// -----------------------DESTINATION MATRIX-------------------------
	malloc_matrix(&destination_matrix);
//------------------------------------------------------------------

	int user_value;
	printf("add = '1', substract = '2', multiply = '3', transpose = '4'\n");
	scanf("%d", &user_value);

	//check for matrix measure legality for certain operations
	if (((user_value == 1 || user_value == 2) && (A_rows == B_rows && A_columns == B_columns))
			|| (user_value == 3 && A_columns == B_rows)
			|| (user_value == 4)
			)
	{
	//execute the process determinde by user_value
		switch (user_value)
		{
			case 1:
				add_matrices(A, B, destination_matrix);
				print_matrix(destination_matrix, A_rows, A_columns);
				break;

			case 2:
				substract_matrices(A, B, destination_matrix);
				print_matrix(destination_matrix, A_rows, A_columns);
				break;

			case 3:
				multiply_matrices(A, B, destination_matrix);
				print_matrix(destination_matrix, A_rows, A_columns);
				break;

			case 4:
				transpose_matrix(B, destination_matrix);
				print_matrix(destination_matrix, A_rows, A_columns);
				break;

			default:
				printf("user value not regonized\n");
				break;
		}
	}
	else
	{
		printf("matrix A and B measures do not support the user suggested operation\n");
	}

	int i;
		// free unused matrix space
	for (i = 0; i < MAX_ROWS; i++)
	{
		free(A[i]);
		free(B[i]);
		free(destination_matrix[i]);
	}

	free(A);
	free(B);
	free(destination_matrix);
	
	return 0;
}

void initialize_matrix(int*** matrix, int a_or_b)
{
	// probe for measures on matrix A
	ask_for_measures(a_or_b);
	printf("(%dx%d)\n\n\n", A_rows, A_columns);
	malloc_matrix(matrix);
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
				printf("element [%d,%d]:\n", y, x);
				scanf("%d", &matrix[y][x]);
			}
		}
	}

	return 0;
}

void print_matrix(int* matrix[], int rows, int columns)
{
	int y, x;	
	
	printf("___________________________________________________________________\n");
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
	printf("___________________________________________________________________\n\n");
}

void ask_for_measures(int a_or_b)
{
	if (a_or_b == 1)
	{
		printf("matrix A #rows\n");
		scanf("%d", &A_rows);
		printf("matrix B #columns\n");
		scanf("%d", &A_columns);
	}
	else if (a_or_b == 2) {
		printf("matrix A #rows\n");
		scanf("%d", &B_rows);
		printf("matrix B #columns\n");
		scanf("%d", &B_columns);
	}
}

void malloc_matrix(int*** matrix)
{
	int j;

	//allocate destination matrix (2-d int array)
	*matrix = (int*)malloc(MAX_ROWS * sizeof *matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		(*matrix)[j] = (int*)malloc(MAX_COLUMNS * sizeof *matrix[j]);
	}	
}
