#include "matrix_algebra.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 5

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


void multiply_matrices(int* A[], int* B[], int* destination[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			//printf("destination[%d][%d]\n= (", y, x);
			//print_vector(A, y, 0, 1);
			//print_vector(B, 0, x, 2);
			//printf("\n");
			destination[y][x] = dot_product(A, B, y, x);
			//printf("\t)\n\n");
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
		//printf("(%d * %d) + ", a[y][i], b[i][x]);
	}
	//printf(" = %d", result);

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


void transpose_matrix(int* C[], int* destination_matrix[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			destination_matrix[x][y] = C[y][x];
		}
	}
}
