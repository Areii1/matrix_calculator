#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "matrix_algebra.h"

#define MAX_ROWS 9
#define MAX_COLUMNS 9

#define FILENAME "matrix.txt"
#define MAXSTRLEN 2000

/* matrix building related functions */
void get_matrix(int* matrix[], int chosen_variable);
int build_matrix(int* matrix[], int rows, int columns);
void print_matrix(int* matrix[], int user_rows, int user_columns);
void malloc_matrix(int*** matrix);

/* file handling related functions */
void write_matrix_to_file(int* matrix[], int user_rows, int user_columns, char* assigned_matrix_identifier);
void read_matrix_from_file_into_variable(char* assigned_matrix_identifier, int varibale);
void clear_matrix_file(void);
void print_matrix_file(void);

/* user related functions */
void input_matrix_measures(int chosen_variable);
void input_matrix_identifier(int* matrix[], int user_rows, int user_columns);

int count_line_length(char* line);

static int A_rows, A_columns, B_rows, B_columns, C_rows, C_columns;
static int **A;
static int **B;
static int **C;
static int chosen_variable;
static char assigned_matrix_identifier[1];
static char searched_matrix_identifier[1];

int main(void)
{	
	int user_choice;

	do 
	{
		printf("------------------------ USER OPTIONS -------------------------------------\n");
		printf("enter a matrix = 1\n");
		printf("give a statement = 2\n");
		printf("read a matrix by name, into a variable = 3\n");
		printf("perform operations on the given matrices = 4\n");
		printf("print earlier matrix entries = '7'\n");
		printf("delete earlier matrix entries = '8'\n");
		printf("exit program = '9'\n");
		printf("---------------------------------------------------------------------------\n");
		

		scanf("%d", &user_choice);
		switch (user_choice)
		{
			case 1:
				printf("variable index to put in? 'A' = 1, 'B' = 2, 'C' = 3\n");
				scanf("%d", &chosen_variable);

				get_matrix(A, chosen_variable);
				
				break;

			case 2:
				printf("can't do that shit yet\n");
				break;

			case 3:

				printf("variable name to search?\n");
				scanf("%s", &searched_matrix_identifier);

				printf("variable index to put in? 'A' = 1, 'B' = 2, 'C' = 3\n");
				scanf("%d", &chosen_variable);

				read_matrix_from_file_into_variable(searched_matrix_identifier, chosen_variable);
				break;

			case 4:

/*
				printf("add = '1', substract = '2', multiply = '3', transpose = '4'\n");
				scanf("%d", &user_choice);

				//check for matrix measure legality for certain operations
				if (((user_choice == 1 || user_choice == 2) && (A_rows == B_rows && A_columns == B_columns))
						|| (user_choice == 3 && A_columns == B_rows)
						|| (user_choice == 4)
						)
				{
				//execute the process determinde by user_choice

					int user_choice;
					int choice_conflict = 0;

					switch (user_choice)
					{
						case 1:
							add_matrices(A, B, C);
							print_matrix(C, A_rows, B_columns);
							break;

						case 2:
							substract_matrices(A, B, C);
							print_matrix(C, A_rows, B_columns);
							break;

						case 3:
							multiply_matrices(A, B, C);
							print_matrix(C, A_rows, B_columns);
							break;

						case 4:
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

				
				break;
*/
			case 7:
				print_matrix_file();
				break;

			case 8:
				clear_matrix_file();	
				break;

			case 9:
				break;

			default:
				printf("value ('%d') not recognized\n", user_choice);
		}
	} while (user_choice != 9);


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

void get_matrix(int* matrix[], int chosen_variable)
{
	if (chosen_variable == 1)
	{
		input_matrix_measures(chosen_variable);
		malloc_matrix(&A);
		build_matrix(A, A_rows, A_columns);
		print_matrix(A, A_rows, A_columns);
		input_matrix_identifier(A, A_rows, A_columns);
		write_matrix_to_file(A, A_rows, A_columns, assigned_matrix_identifier);
	}
	else if (chosen_variable == 2)
	{
		input_matrix_measures(chosen_variable);
		malloc_matrix(&B);
		build_matrix(B, B_rows, B_columns);
		print_matrix(B, B_rows, B_columns);
		input_matrix_identifier(B, B_rows, B_columns);
		write_matrix_to_file(B, B_rows, B_columns, assigned_matrix_identifier);
	}
	else if (chosen_variable == 3)
	{
		input_matrix_measures(chosen_variable);
		malloc_matrix(&C);
		build_matrix(C, C_rows, C_columns);
		print_matrix(C, C_rows, C_columns);
		input_matrix_identifier(C, C_rows, C_columns);
		write_matrix_to_file(C, C_rows, C_columns, assigned_matrix_identifier);
	}
}
/*
void complete_matrix(int* matrix[])
{
		initialize_matrix(&matrix, chosen_variable);
		build_matrix(matrix, A_rows, A_columns);
		print_matrix(matrix, A_rows, A_columns);
		input_matrix_identifier(matrix, A_rows, A_columns);
		write_matrix_to_file(matrix, A_rows, A_columns, assigned_matrix_identifier);
}
*/
int build_matrix(int* matrix[], int rows, int columns)
{
	int x, y;

	for (y = 0; y < rows; y++)
	{
		for (x = 0; x < columns; x++)
		{

				printf("element [%d,%d]: ", y, x);
				scanf("%d", &matrix[y][x]);
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

void input_matrix_measures(int chosen_variable)
{
	int measure_conflict = 0;

	do 
	{
		if (chosen_variable == 1)
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
		else if (chosen_variable == 2) 
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
		else if (chosen_variable = 3) 
		{
			printf("C #rows: ");
			scanf("%d", &C_rows);
			printf("C #columns: ");
			scanf("%d", &C_columns);
			measure_conflict = 0;

			if (C_rows > MAX_ROWS || C_columns > MAX_COLUMNS)
			{
				measure_conflict = 1;
				printf("MAX_ROWS = %d, MAX_COLUMS = %d... try again\n", MAX_ROWS, MAX_COLUMNS);
			}
		}
	} while (measure_conflict == 1);
	
	/* print the measures */
	if (chosen_variable == 1)
	{
		printf("A = (%dx%d)\n\n", A_rows, A_columns);
	}
	else if (chosen_variable == 2)
	{	
		printf("B = (%dx%d)\n\n", B_rows, B_columns);
	}
	else if (chosen_variable == 3)
	{	
		printf("C = (%dx%d)\n\n", C_rows, C_columns);
	}
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


void print_matrix_file(void)
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

void write_matrix_to_file(int* matrix[], int user_rows, int user_columns, char* assigned_matrix_identifier)
{
	FILE *fp;
	fp = fopen(FILENAME, "a");
	
	fflush(fp);
	fprintf(fp, "<%s>", assigned_matrix_identifier);
	fprintf(fp, "(%d,%d)=", user_rows, user_columns);
	int x, y;

	fputs("{", fp);
	for (y = 0; y < user_rows; y++)
	{
		fputs("{", fp);
		for (x = 0; x < user_columns; x++)
		{
			fprintf(fp, "%d,", matrix[y][x]);
		}
		fputs("}", fp);
	}
	fputs("}", fp);
	fputs("|\n", fp);

	fclose(fp);
}

void clear_matrix_file(void)
{
	FILE *fp;
	fp = fopen(FILENAME, "w");
	fclose(fp);

	printf("\nsuccesfully deleted all entries in %s\n", FILENAME);
}

void input_matrix_identifier(int* matrix[], int user_rows, int user_columns)
{
	printf("give a one character long name for the matrix\n");
	scanf("%s", assigned_matrix_identifier);
}

/* search matrix by name from matrix.txt file and read it to a variable
in the program (A or B or C).
*/
void read_matrix_from_file_into_variable(char* assigned_matrix_identifier, int storage_variable)
{
	char searched_variable_char = assigned_matrix_identifier[0];

	FILE *fp;
	fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];

	int current_matrix_rows = 0;
	int current_matrix_columns = 0;

	malloc_matrix(&A);	
	malloc_matrix(&B);
	malloc_matrix(&C);

	if (fp != 0)
	{
		while (fgets(line, sizeof(line), fp) != 0)
		{
			/* line[1] has matrix identifier char, check if it matches
				 the searched character */
			if (line[1] == searched_variable_char)
			{
				int i;
				int row_index = 0;
				int column_index = 0;

				int line_length = count_line_length(line);


				current_matrix_rows = (int)(line[4] - '0');
				current_matrix_columns = (int)(line[6] - '0');
				
				char current_number_string[20];

				/* loop the entire line, (one matrix), start after the meta info */
				for (i = 10; i < line_length; i++)
				{
					int x;
					/* loop through current_number_string to make sure it does not
						 contain previous garbage values */
					for (x = 0; x <= 20; x++)
					{
						current_number_string[x] = '\0';
					}

					if (isdigit(line[i]))
					{
						int j;
						/* if the first layer loop detects a digit, go to a second
							 layer loop that checks if consequent char is also a digit
							 and assigns the digits onto the string. Loops until it reaches 
							 a non-digit char */
						for (j = 0; j < 6; j++)
						{
							if (isdigit(line[i + j]))
							{
								current_number_string[j] = line[i + j];
							}
							else
							{
								current_number_string[j + 1] = '\0';
								break;
							}
						}
						/* add j to i so the first layer loop continues from the correct spot */
						i = i + j;
				
						int current_number = 0;
						/* convert and save the current_number_string as an integer */
						current_number = atoi(current_number_string);
						
						/* put the number in the right matrix as requested by the user */
						if (storage_variable == 1)
						{									
							A[row_index][column_index] = current_number;
							column_index++;

							if (column_index == current_matrix_columns)
							{
								row_index++;
								column_index = 0;
							}
						}
						else if (storage_variable == 2)
						{
							B[row_index][column_index] = current_number;
							column_index++;

							if (column_index == current_matrix_columns)
							{
								row_index++;
								column_index = 0;
							}
						}
						else if (storage_variable == 3)
						{
							C[row_index][column_index] = current_number;
							column_index++;

							if (column_index == current_matrix_columns)
							{
								row_index++;
								column_index = 0;
							}
						}
					}
						
					if (row_index == MAX_ROWS - 1 && column_index == MAX_COLUMNS - 1)
					{
						break;
					}
				}
			}
		}

		/* print the right matrix as requested by the user */
		if (storage_variable == 1)
		{
			print_matrix(A, current_matrix_rows, current_matrix_columns);
		}
		else if (storage_variable == 2)
		{
			print_matrix(B, current_matrix_rows, current_matrix_columns);
		}
		else if (storage_variable == 3)
		{
			print_matrix(C, current_matrix_rows, current_matrix_columns);
		}
	}
	else
	{
		printf("File %s cannot be opened!\n", FILENAME);
	}

	fclose(fp);
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
