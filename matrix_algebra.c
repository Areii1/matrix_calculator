#include "matrix_algebra.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 9
#define MAX_COLUMNS 9

int leading_zeros_table[MAX_COLUMNS];

void add_matrices(double* A[], double* B[], double* C[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			C[y][x] = A[y][x] + B[y][x];
		}
	}
}

void substract_matrices(double* A[], double* B[], double* C[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			B[y][x] = B[y][x] * -1;
			C[y][x] = A[y][x] + B[y][x];
		}
	}
}


void multiply_matrices(double* A[], double* B[], double* C[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			C[y][x] = dot_product(A, B, y, x);
		}
	}
}

double dot_product(double* a[], double* b[], int y, int x)
{
	int i;
	double result = 0;

	for (i = 0; i < MAX_COLUMNS; i++)
	{
		result = result + (a[y][i] * b[i][x]);
	}
	return result;
}

void print_vector(double* C[], int y, int x, int a_or_b)
{
	int i;
	
	for (i = 0; i < MAX_COLUMNS; i++)
	{
		if (a_or_b == 1)
		{
			printf("A[0][%d] = %lf\n", i,  C[y][i]);
		}
		else if (a_or_b == 2)
		{
			printf("B[%d][0] = %lf\n", i,  C[i][x]);
		}
	}
}

void transpose_matrix(double* A[], double* C[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			C[x][y] = A[y][x];
		}
	}
}

/*
receives a pointer to a matrix with matrix_rows amount of non-degenerate rows, 
*/
void gaussian_elimination(double* matrix[], double* destination_matrix[],
		int rows, int columns)
{

	organize_matrix(matrix, destination_matrix, rows, columns);
	
	printf("matrix before eliminate_below_values\n");
	print_matrix(matrix, rows, columns);

	eliminate_below_values(matrix, destination_matrix, rows, columns);

	
	printf("matrix after eliminate_below_values\n");
	print_matrix(matrix, rows, columns);

	int x, y;
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
			destination_matrix[y][x] = matrix[y][x];
		}
	}
}

void organize_matrix(double* matrix[], double* destination_matrix[], int rows, int columns)
{
	int i, a, temp;
	int x, y;

	get_leading_zeros_table(matrix, rows, columns);

	/* copy the matrix to the destination_matrix */
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
			destination_matrix[y][x] = matrix[y][x];
		}
	}

	/* insertion sort */
	for (i = 1; i < rows; i++)
	{
		a = i;

		while (a > 0 && leading_zeros_table[a] < leading_zeros_table[a - 1])
		{
			temp = leading_zeros_table[a];
			swap_rows(matrix, destination_matrix, a, a - 1, rows, columns);
			leading_zeros_table[a] = leading_zeros_table[a - 1];
			leading_zeros_table[a - 1] = temp;

			a--;
		}
	}
}

void get_leading_zeros_table(double* matrix[], int rows, int columns)
{
	int leading_zeros_counter = 0;
	int y, x, i;

	for (y = 0; y < rows; y++)
	{
		leading_zeros_counter = 0;
		for (x = 0; x < columns; x++)
		{
			if (matrix[y][0] == 0)
			{
				leading_zeros_counter++;
				for (i = 1; i < columns; i++)
				{
					x++;
					if (matrix[y][i] == 0)
					{
						leading_zeros_counter++;
					}
					else
					{
						leading_zeros_table[y] = leading_zeros_counter;
						leading_zeros_counter = 0;
						break;
					}
				}
			}
			else
			{
				leading_zeros_table[y] = 0;
				leading_zeros_counter = 0;
			}
				
			if (leading_zeros_counter != 0)
			{
				break;
			}
		}
	}
}

void swap_rows(double* matrix[], double* destination_matrix[], int a, int b,
		int rows, int columns)
{
	int x, y, temp;

	for (x = 0; x < columns; x++)
	{
		temp = matrix[a][x];
		matrix[a][x] = matrix[b][x];
		matrix[b][x] = temp;
	}

	/* copy the matrix to the destination_matrix */
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
			destination_matrix[y][x] = matrix[y][x];
		}
	}
}

void eliminate_below_values(double* matrix[], double* destination_matrix[],
		int rows,	int columns)
{
	double vector[rows];
	int i, j, value_to_eliminate;
	double row_leading_value;
	int leading_value_column;
	int leading_value_row;

	for (i = 0; i < rows; i++)
	{
		get_leading_zeros_table(matrix, rows, columns);
		row_leading_value = matrix[i][leading_zeros_table[i]];
		leading_value_column = leading_zeros_table[i];
		leading_value_row = i;

		
		printf("matrix inside eliminate_below_values, i = %d\n", i);
		print_matrix(matrix, rows, columns);
		
		for (j = 0; j < rows; j++)
		{
			vector[j] = matrix[j][leading_zeros_table[i]];
		}
		perform_column_elimination(matrix, vector, row_leading_value,
				leading_value_column, leading_value_row, rows, columns);
	}
}

void perform_column_elimination(double* matrix[], double vector[], 
		double row_leading_value, int leading_value_column, 
		int leading_value_row, int rows, int columns)
{

	/* print vector */
	int k;
	for (k = 0; k < rows; k++)
	{
		printf("vector[%d] = %lf\t", k, vector[k]);
	}
	printf("\n\n");

	printf("row_leading_value = %lf, leading_value_row = %d, leading_value_column = %d\n\n", 
			row_leading_value, leading_value_row, leading_value_column);

	double a;
	double operation_table[rows];
	int i, x, y;

	for (i = 0; i < rows - 1; i++)
	{
		a = (-1) * (vector[i + leading_value_row + 1]/row_leading_value);
		operation_table[i] = a;
	}

	/* apply to the whole matrix */

	int operation_counter = 0;

	for (y = leading_value_row + 1; y < rows; y++)
	{
		for (x = leading_value_column; x < columns; x++)
		{
			matrix[y][x] = (matrix[leading_value_row][x]
				* operation_table[operation_counter]) + matrix[y][x];
		}
		operation_counter++;
	}
	
	/* print operation table */
	for (k = 0; k < rows; k++)
	{
		printf("operation_table[%d] = %lf\t", k, operation_table[k]);
	}
	printf("\n\n");
}
