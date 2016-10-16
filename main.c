#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix_algebra.h"

#define MAX_ROWS 10
#define MAX_COLUMNS 10

#define FILENAME "matrix.txt"
#define MAXSTRLEN 2000

int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int user_rows, int user_columns);
void ask_for_measures(int a_or_b);
void initialize_matrix(int*** matrix, int a_or_b);
void malloc_matrix(int*** matrix);

void read_matrix(void);
void append_matrix(int* matrix[], char* name, int user_rows, int user_columns);
void clear_file(void);
void ask_for_name(int* matrix[]);
void read_matrix_into_variable(char* name, int varibale);
int count_line_length(char* line);

int A_rows, A_columns, B_rows, B_columns;
int **A;
int **B;
int **C;

int main(void)
{	
	int user_value;

	do 
	{
		printf("------------------------ USER OPTIONS -------------------------------------\n");
		printf("enter a matrix = 1\n");
		printf("give a statement = 2\n");
		printf("read a matrix by name, into a variable = 3\n");
		printf("print earlier matrix entries = '7'\n");
		printf("delete earlier matrix entries = '8'\n");
		printf("exit program = '9'\n");
		printf("---------------------------------------------------------------------------\n");
		
		char matrix_name[1];
		int A_B_or_C;

		scanf("%d", &user_value);
		switch (user_value)
		{
			case 1:
				break;

			case 2:
				printf("can't do that shit yet\n");
				break;

			case 3:

				printf("variable name to search?\n");
				scanf("%s", &matrix_name);

				printf("variable index to put in? 'A' = 1, 'B' = 2, 'C' = 3\n");
				scanf("%d", &A_B_or_C);

				read_matrix_into_variable(matrix_name, A_B_or_C);
				break;
			case 7:
				read_matrix();
				break;

			case 8:
				clear_file();	
				break;

			case 9:
				exit(0);

			default:
				printf("value ('%d') not recognized\n", user_value);
		}
	} while (user_value != 1);

// ----------------------FIRST MATRIX -------------------------------
	initialize_matrix(&A, 1);
	build_matrix(A, A_rows, A_columns);
	print_matrix(A, A_rows, A_columns);
	ask_for_name(A);
//-------------------------------------------------------------------

//----------------------- SECOND MATRIX -----------------------------
	initialize_matrix(&B, 2);
	build_matrix(B, B_rows, B_columns);
	print_matrix(B, B_rows, B_columns);
	ask_for_name(B);
//-------------------------------------------------------------------

// -----------------------DESTINATION MATRIX-------------------------
	malloc_matrix(&C);
//------------------------------------------------------------------

	printf("add = '1', substract = '2', multiply = '3', transpose = '4'\n");
	scanf("%d", &user_value);

	//check for matrix measure legality for certain operations
	if (((user_value == 1 || user_value == 2) && (A_rows == B_rows && A_columns == B_columns))
			|| (user_value == 3 && A_columns == B_rows)
			|| (user_value == 4)
			)
	{
	//execute the process determinde by user_value

		int user_choice;
		int choice_conflict = 0;

		switch (user_value)
		{
			case 1:
				add_matrices(A, B, C);
				print_matrix(C, MAX_ROWS, MAX_COLUMNS);
				break;

			case 2:
				substract_matrices(A, B, C);
				print_matrix(C, MAX_ROWS, MAX_COLUMNS);
				break;

			case 3:
				multiply_matrices(A, B, C);
				print_matrix(C, MAX_ROWS, MAX_COLUMNS);
				break;

			case 4:
			//	int user_choice;
			//	int choice_conflict = 0;
				printf("transpose A = 1, B = 2\n");

				do
				{
					scanf("%d", &user_choice);
					
					if (user_choice == 1)
					{
						transpose_matrix(A, C);
						print_matrix(C, MAX_ROWS, MAX_COLUMNS);
						choice_conflict = 0;
					}
					else if (user_choice == 2)
					{
						transpose_matrix(B, C);
						print_matrix(C, MAX_ROWS, MAX_COLUMNS);
						choice_conflict = 0;
					}
					else
					{
						printf("did not recognize '%d', A = 1, B = 2\n", user_choice);
						choice_conflict = 1;
					}
				} while (choice_conflict == 1);
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

	ask_for_name(C);

	int i;
	// free unused matrix space
	for (i = 0; i < MAX_ROWS; i++)
	{
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);
	
	return 0;
}

void initialize_matrix(int*** matrix, int a_or_b)
{
	// probe for measures on matrix A
	ask_for_measures(a_or_b);
	
	if (a_or_b == 1)
	{
		printf("A = (%dx%d)\n\n", A_rows, A_columns);
	}
	else if (a_or_b == 2)
	{	
		printf("B = (%dx%d)\n\n", B_rows, B_columns);
	}

	malloc_matrix(matrix);
}

int build_matrix(int* matrix[], int rows, int columns)
{
	int x, y;

	for (y = 0; y < MAX_ROWS; y++)
	{
		for (x = 0; x < MAX_COLUMNS; x++)
		{
			if ((y >= rows && y < MAX_ROWS) || (x >= columns && x < MAX_COLUMNS))
			{
				matrix[y][x] = 0;
			}
			else
{
				printf("element [%d,%d]: ", y, x);
				scanf("%d", &matrix[y][x]);
			}
		}
	}
	return 0;
}

void print_matrix(int* matrix[], int user_rows, int user_columns)
{
	int y, x;	
	
	printf("___________________________________________________________________\n");
	for (y = 0; y < user_rows; y++)
	{
		printf("\n");
		for (x = 0; x < user_columns; x++)
		{
			printf("%d\t", matrix[y][x]);
		}
		printf("\n");
	}
	printf("___________________________________________________________________\n\n");
}

void ask_for_measures(int a_or_b)
{
	int measure_conflict = 0;

	do 
	{
		if (a_or_b == 1)
		{
			printf("A #rows: ");
			scanf("%d", &A_rows);
			printf("A #columns: ");
			scanf("%d", &A_columns);
			measure_conflict = 0;

			if (A_rows > MAX_ROWS || A_columns > MAX_COLUMNS)
			{
				measure_conflict = 1;
				printf("MAX_ROWS = %d, MAX_COLUMS = %d... try again\n", MAX_ROWS, MAX_COLUMNS);
			}
		}
		else if (a_or_b == 2) 
		{
			printf("B #rows: ");
			scanf("%d", &B_rows);
			printf("B #columns: ");
			scanf("%d", &B_columns);
			measure_conflict = 0;

			if (B_rows > MAX_ROWS || B_columns > MAX_COLUMNS)
			{
				measure_conflict = 1;
				printf("MAX_ROWS = %d, MAX_COLUMS = %d... try again\n", MAX_ROWS, MAX_COLUMNS);
			}
		}
	} while (measure_conflict == 1);
}

void malloc_matrix(int*** matrix)
{
	int j;

	*matrix = (int*)malloc(MAX_ROWS * sizeof *matrix);
	for (j = 0; j < MAX_ROWS; j++)
	{
		(*matrix)[j] = (int*)malloc(MAX_COLUMNS * sizeof *matrix[j]);
	}	
}


void read_matrix(void)
{
	FILE *fp;
	fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];
	
	if (fp != 0)
	{
		while (fgets(line, sizeof(line), fp) != 0)
		{
			printf("%s", line);
		}
		fclose(fp);
	}
	else
	{
		printf("File %s cannot be opened!\n", FILENAME);
	}
}

void append_matrix(int* matrix[], char* name, int user_rows, int user_columns)
{
	FILE *fp;
	fp = fopen(FILENAME, "a");

	fprintf(fp, "<%s>=", name);
	int x, y;

	fputs("{", fp);
	for (x = 0; x < user_rows; x++)
	{
		fputs("{", fp);
		for (y = 0; y < user_columns; y++)
		{
			fprintf(fp, "%d,", matrix[y][x]);
		}
		fputs("}", fp);
	}
	fputs("}", fp);
	fputs("|\n", fp);
}

void clear_file(void)
{
	FILE *fp;
	fp = fopen(FILENAME, "w");
	fclose(fp);

	printf("\nsuccesfully deleted all entries in %s\n", FILENAME);
}

void ask_for_name(int* matrix[])
{
	printf("give a one character long name for the matrix\n");
	char name[1];
	scanf("%s", &name);
	append_matrix(matrix, name, MAX_ROWS, MAX_COLUMNS);
}

/* search matrix by name from matrix.txt file and read it to a variable
in the program (A or B or C).
*/
void read_matrix_into_variable(char* name, int storage_variable)
{
	char searched_variable_char = name[0];

	FILE *fp;
	fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];
	
	if (fp != 0)
	{
		while (fgets(line, sizeof(line), fp) != 0)
		{
			if (line[0] == '<' && line[1] == searched_variable_char)
			{
				int i;

				int row_index = 0;
				int column_index = 0;

				int line_length = count_line_length(line);
				
				printf("line_length = %d\n", line_length);

				malloc_matrix(&A);
				
				char current_number_string[20];

				for (i = 0; i < line_length; i++)
				{
					int x;
					for (x = 0; x <= 20; x++)
					{
						current_number_string[x] = '\0';
					}

					printf("line[%d] = %d\n", i, line[i]);
					if (isdigit(line[i]))
					{
						int j;
						for (j = 0; j < 6; j++)
						{
							if (isdigit(line[i + j]))
							{
								current_number_string[j] = line[i + j];
							}
							else
							{
								printf("%d\n", j);
								current_number_string[j + 1] = '\0';
								break;
							}
						}
						i = i + j;
				
						int current_number = 0;
						current_number = atoi(current_number_string);
						printf("current_number_string = %d\n", current_number);
						
						if (storage_variable == 1)
						{									
							A[row_index][column_index] = current_number;
							column_index++;

							if (column_index == 10)
							{
								row_index++;
								column_index = 0;
							}
						}
					}
						
					if (row_index == 9 && column_index == 9)
					{
						break;
					}
				}
			}
		}
		fclose(fp);
		print_matrix(A, MAX_ROWS, MAX_COLUMNS);
	}
	else
	{
		printf("File %s cannot be opened!\n", FILENAME);
	}
}

int count_line_length(char* line)
{
	int i;
	int counter = 0;

	for (i = 0; i <= MAXSTRLEN; i++)
	{
		counter++;
		if (line[i] == '|')
		{
			return counter;
		}
	}
	return -1;
}
