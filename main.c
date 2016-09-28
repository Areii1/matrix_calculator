#include <stdio.h>
#include <stdlib.h>

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int rows, int columns);
// void add_matrices(int* A[], int first_rows, int first_columns, int* B[], int second_rows, int second_columns int* destination[]);
// int copy_matrix(int *destination_matrix, int *source_matrix);

/*
typedef int m_2x1[2][1];
typedef int m_2x2[2][2];
typedef int m_2x3[2][3];
typedef int m_2x4[2][4];
typedef int m_2x5[2][5];
typedef int m_3x1[3][1];
typedef int m_3x2[3][2];
typedef int m_3x3[3][3];
typedef int m_3x4[3][4];
typedef int m_3x5[3][5];
typedef int m_4x1[4][1];
typedef int m_4x2[4][2];
typedef int m_4x3[4][3];
typedef int m_4x4[4][4];
typedef int m_4x5[4][5];
typedef int m_5x1[5][1];
typedef int m_5x2[5][2];
typedef int m_5x3[5][3];
typedef int m_5x4[5][4];
typedef int m_5x5[5][5];
*/

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
	printf("preferred matrix: %dx%d\n", first_rows, first_columns);
	
	//allocate matrix (2-d int array)
	first_matrix = malloc(MAX_ROWS * sizeof *first_matrix);
	for (i = 0; i < MAX_ROWS; i++)
	{
		first_matrix[i] = malloc(MAX_COLUMNS * sizeof *first_matrix[i]);
	}

	//pass allocated matrix for element probing
	build_matrix(first_matrix, first_rows, first_columns);
	print_matrix(first_matrix, first_rows, first_columns);

//----------------------- SECOND MATRIX -----------------------
	int second_rows, second_columns, j;
	int **second_matrix;

	//probe for measures
	printf("provide information for the second matrix\n");
	printf("give number of rows\n");
	scanf("%d", &second_rows);
	printf("give number of columns\n");
	scanf("%d", &second_columns);
	printf("preferred matrix: %dx%d\n", second_rows, second_columns);
	
	//allocate matrix (2-d int array)
	second_matrix = malloc(MAX_ROWS * sizeof *second_matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		second_matrix[j] = malloc(MAX_COLUMNS * sizeof *second_matrix[i]);
	}

	//pass allocated matrix for element probing
	build_matrix(second_matrix, second_rows, second_columns);
	print_matrix(second_matrix, second_rows, second_columns);



	// free unused matrix space
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

/*
void add_matrices(int* A[], int first_rows, int first_columns, int* B[], int second_rows, second_columns, int* destination[])
{
	// check if measures match
	if ((first_rows != second_rows) || (first_columns != second_columns))
	{
		return;
	}

	
}
*/

