#include <stdio.h>
#include <stdlib.h>
#include "matrix_algebra.h"

#define MAX_ROWS 5
#define MAX_COLUMNS 5

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);

int first_rows, first_columns, second_rows, second_columns;

int main(void)
{
	// ------------------------- FIRST MATRIX ---------------------------
	int i;
	int **first_matrix;

	// probe for measures
	printf("matrix A #rows\n");
	scanf("%d", &first_rows);
	printf("matrix B #columns\n");
	scanf("%d", &first_columns);
	printf("A (%dx%d)\n\n\n", first_rows, first_columns);
	
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
	int j;
	int **second_matrix;

	//probe for measures
	printf("matrix B #rows\n");
	scanf("%d", &second_rows);
	printf("matrix B  #columns\n");
	scanf("%d", &second_columns);
	printf("B (%dx%d)\n\n\n", second_rows, second_columns);
	
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
	
	int user_value;

	printf("add or substract?\n");
	printf("add = '1', substract = '2', multiply = '3'\n");
	scanf("%d", &user_value);

	int **destination_matrix;

	//allocate destination matrix (2-d int array)
	destination_matrix = malloc(MAX_ROWS * sizeof *destination_matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		destination_matrix[j] = malloc(MAX_COLUMNS * sizeof *destination_matrix[i]);
	}
	

	// MULTIPLY NOT WORKING PROPERLY YET
	/*
	if (user_value == 3)
	{
		multiply_matrices(first_matrix, second_matrix, destination_matrix);
		printf("--------------------- DESTINATION MATRIX --------------------\n");
		print_matrix(destination_matrix, first_rows, first_columns);
		printf("-------------------------------------------------------------\n");
	}
	*/
	/*elseif*/if (first_rows == second_rows && first_columns == second_columns)
	{
		if (user_value == 1)
		{
			add_matrices(first_matrix, second_matrix, destination_matrix);
			printf("-------------------- DESTINATION MATRIX -------------------\n");
			print_matrix(destination_matrix, first_rows, first_columns);
			printf("-----------------------------------------------------------\n");
		}
		else if (user_value == 2)
		{
			substract_matrices(first_matrix, second_matrix, destination_matrix);
			printf("-------------------- DESTINATION MATRIX -------------------\n");
			print_matrix(destination_matrix, first_rows, first_columns);
			printf("-----------------------------------------------------------\n");
		}
		else
		{
			printf("user value '%d' not recognized\n", user_value);
		}
	}
	else
	{
		printf("A and B not the same size\n");
	}

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

