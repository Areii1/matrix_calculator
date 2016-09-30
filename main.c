#include <stdio.h>
#include <stdlib.h>
#include "matrix_algebra.h"

#define MAX_ROWS 5
#define MAX_COLUMNS 5

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);
void ask_for_measures(int a_or_b);
//void malloc_matrix(int** matrix);

int A_rows, A_columns, B_rows, B_columns;

int main(void)

{
	// ------------------------- FIRST MATRIX ---------------------------
	int i;
	int **A;

	// probe for measures on matrix A
	ask_for_measures(1);
	printf("A (%dx%d)\n\n\n", A_rows, A_columns);
	
	//allocate first matrix (2-d int array)
	A = malloc(MAX_ROWS * sizeof *A);
	for (i = 0; i < MAX_ROWS; i++)
	{
		A[i] = malloc(MAX_COLUMNS * sizeof *A[i]);
	}

	//pass allocated matrix for element probing
	build_matrix(A, A_rows, A_columns);
	printf("-------------------- FIRST MATRIX -------------------\n");
	print_matrix(A, A_rows, A_columns);
	printf("-----------------------------------------------------\n");

//----------------------- SECOND MATRIX -----------------------
	int j;
	int **B;

	//probe for measures
	ask_for_measures(2);
	printf("B (%dx%d)\n\n\n", B_rows, B_columns);
	
	//allocate second matrix (2-d int array)
	B = malloc(MAX_ROWS * sizeof *B);
	for (j = 0; j < MAX_ROWS; j++)
	{
		B[j] = malloc(MAX_COLUMNS * sizeof *B[j]);
	}

	//pass allocated matrix for element probing
	build_matrix(B, B_rows, B_columns);
	printf("-------------------- SECOND MATRIX -------------------\n");
	print_matrix(B, B_rows, B_columns);
	printf("------------------------------------------------------\n");
	
	int user_value;

	printf("add = '1', substract = '2', multiply = '3', transpose = '4'\n");
	scanf("%d", &user_value);

	int **destination_matrix;

	//allocate destination matrix (2-d int array)
	destination_matrix = malloc(MAX_ROWS * sizeof *destination_matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		destination_matrix[j] = malloc(MAX_COLUMNS * sizeof *destination_matrix[i]);
	}	

	if (user_value == 4)
	{
		transpose_matrix(B, destination_matrix);
		printf("--------------------- DESTINATION MATRIX --------------------\n");
		print_matrix(destination_matrix, A_rows, A_columns);
		printf("-------------------------------------------------------------\n");
	}

	// multiplication
	if (user_value == 3 && A_columns == B_rows)
	{
		multiply_matrices(A, B, destination_matrix);
		printf("--------------------- DESTINATION MATRIX --------------------\n");
		print_matrix(destination_matrix, A_rows, A_columns);
		printf("-------------------------------------------------------------\n");
	}
	else
	{
		printf("matrix A and B measures are not suited for multiplication\n");
	}
	// addition or substraction
	if (A_rows == B_rows && A_columns == B_columns)
	{
		if (user_value == 1)
		{
			add_matrices(A, B, destination_matrix);
			printf("-------------------- DESTINATION MATRIX -------------------\n");
			print_matrix(destination_matrix, A_rows, A_columns);
			printf("-----------------------------------------------------------\n");
		}
		else if (user_value == 2)
		{
			substract_matrices(A, B, destination_matrix);
			printf("-------------------- DESTINATION MATRIX -------------------\n");
			print_matrix(destination_matrix, A_rows, A_columns);
			printf("-----------------------------------------------------------\n");
		}
		else
		{
			printf("user value '%d' not recognized\n", user_value);
		}
	}
	else if (user_value == 1 || user_value == 2)
	{
		printf("matrix A and B measures not suited for addition or substraction\n");
	}

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

/*
void malloc_matrix(int** matrix)
{
	int j;

	//allocate destination matrix (2-d int array)
	matrix = malloc(MAX_ROWS * sizeof *matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		matrix[j] = malloc(MAX_COLUMNS * sizeof *matrix[j]);
	}
	
}
*/


