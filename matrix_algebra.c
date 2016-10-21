#include "matrix_algebra.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 9
#define MAX_COLUMNS 9

void add_matrices(int* A[], int* B[], int* C[])
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

void substract_matrices(int* A[], int* B[], int* C[])
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


void multiply_matrices(int* A[], int* B[], int* C[])
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

int dot_product(int* a[], int* b[], int y, int x)
{
	int i;
	int result = 0;

	for (i = 0; i < MAX_COLUMNS; i++)
	{
		result = result + (a[y][i] * b[i][x]);
	}
	return result;
}

void print_vector(int* C[], int y, int x, int a_or_b)
{
	int i;
	
	for (i = 0; i < MAX_COLUMNS; i++)
	{
		if (a_or_b == 1)
		{
			printf("A[0][%d] = %d\n", i,  C[y][i]);
		}
		else if (a_or_b == 2)
		{
			printf("B[%d][0] = %d\n", i,  C[i][x]);
		}
	}
}

void transpose_matrix(int* A[], int* C[])
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
void gaussian_elimination(int* matrix[], int* destination_matrix[],
		int rows, int columns)
{
	int y, x;

	organize_matrix(matrix, rows, columns);
/*
	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{
		}
	}
	*/
}

void organize_matrix(int* matrix[], int rows, int columns)
{
	int leading_zeros_table[rows];
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
	//	printf("leading_zeros_counter = %d\n", leading_zeros_counter);
	}

	for (i = 0; i < rows; i++)
	{
		printf("table[%d] = %d\n", i, leading_zeros_table[i]);
	}
}
