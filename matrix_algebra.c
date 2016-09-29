#include "matrix_algebra.h"

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

/*
void multiply_matrices(int* A[], int* B[], int* destination[])
{
	int y, x;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			destination[y][x] = dot_product(A[x], B[y]);
		}
	}
}

int dot_product(int u[], int v[])
{
	int i;
	int result = 0;

	for (i = 0; i < MAX_COLUMNS; i++)
	{
		result = result + (u[i] * v[i]);
	}

	return result;
}
*/

