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
void complete_matrix(int* matrix[]);
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

static int A_rows, A_columns, B_rows, B_columns, C_rows, C_columns, chosen_variable_rows, chosen_variable_columns;
static int **slot_A;
static int **slot_B;
static int **slot_C;
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
				printf("variable index to put in? 'slot_A' = 1, 'slot_B' = 2, 'slot_C' = 3\n");
				scanf("%d", &chosen_variable);
		
				if (chosen_variable == 1)
				{
					complete_matrix(slot_A);
				}
				else if (chosen_variable == 2)
				{
					complete_matrix(slot_B);
				}
				else if (chosen_variable == 3)
				{
					complete_matrix(slot_C);
				}

				break;

			case 2:
				printf("can't do that shit yet\n");
				break;

			case 3:

				printf("variable name to search?\n");
				scanf("%s", &searched_matrix_identifier);

				printf("variable index to put in? 'slot_A' = 1, 'slot_B' = 2, 'slot_C' = 3\n");
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
							add_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, A_rows, B_columns);
							break;

						case 2:
							substract_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, A_rows, B_columns);
							break;

						case 3:
							multiply_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, A_rows, B_columns);
							break;

						case 4:
							printf("transpose slot_A = 1, slot_B = 2\n");

							do
							{
								scanf("%d", &user_choice);
								
								if (user_choice == 1)
								{
									transpose_matrix(slot_A, slot_C);
									print_matrix(slot_C, MAX_ROWS, MAX_COLUMNS);
									choice_conflict = 0;
								}
								else if (user_choice == 2)
								{
									transpose_matrix(slot_B, slot_C);
									print_matrix(slot_C, MAX_ROWS, MAX_COLUMNS);
									choice_conflict = 0;
								}
								else
								{
									printf("did not recognize '%d', slot_A = 1, slot_B = 2\n", user_choice);
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
					printf("matrix slot_A and slot_B measures do not support the user suggested operation\n");
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
		free(slot_A[i]);
		free(slot_B[i]);
		free(slot_C[i]);
	}
	free(slot_A);
	free(slot_B);
	free(slot_C);
	
	return 0;
}

void complete_matrix(int* matrix[])
{
		input_matrix_measures(chosen_variable);
		malloc_matrix(&slot_A);
		build_matrix(slot_A, chosen_variable_rows, chosen_variable_columns);
		print_matrix(slot_A, chosen_variable_rows, chosen_variable_columns);
		input_matrix_identifier(slot_A, chosen_variable_rows, chosen_variable_columns);
		write_matrix_to_file(slot_A, chosen_variable_rows, chosen_variable_columns, assigned_matrix_identifier);
}

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
		printf("#rows: ");
		scanf("%d", &chosen_variable_rows);
		printf("#columns: ");
		scanf("%d", &chosen_variable_columns);	
		
		if (chosen_variable_rows > MAX_ROWS || chosen_variable_columns > MAX_COLUMNS)
		{
			measure_conflict = 1;
			printf("MAX_ROWS = %d, MAX_COLUMS = %d... try again\n", MAX_ROWS, MAX_COLUMNS);
		}

	} while (measure_conflict == 1);
	
	/* print and save the measures */
	if (chosen_variable == 1)
	{
		A_rows = chosen_variable_rows;
		A_columns = chosen_variable_columns;
		printf("slot_A = (%dx%d)\n\n", A_rows, A_columns);
	}
	else if (chosen_variable == 2)
	{	
		B_rows = chosen_variable_rows;
		B_columns = chosen_variable_columns;
		printf("slot_B = (%dx%d)\n\n", B_rows, B_columns);
	}
	else if (chosen_variable == 3)
	{	
		C_rows = chosen_variable_rows;
		C_columns = chosen_variable_columns;
		printf("slot_C = (%dx%d)\n\n", C_rows, C_columns);
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
in the program (slot_A or slot_B or slot_C).
*/
void read_matrix_from_file_into_variable(char* assigned_matrix_identifier, int storage_variable)
{
	char searched_variable_char = assigned_matrix_identifier[0];

	FILE *fp;
	fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];

	int current_matrix_rows = 0;
	int current_matrix_columns = 0;

	malloc_matrix(&slot_A);	
	malloc_matrix(&slot_B);
	malloc_matrix(&slot_C);

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
							slot_A[row_index][column_index] = current_number;
						}
						else if (storage_variable == 2)
						{
							slot_B[row_index][column_index] = current_number;

						}
						else if (storage_variable == 3)
						{
							slot_C[row_index][column_index] = current_number;

						}

						column_index++;

						if (column_index == current_matrix_columns)
						{
							row_index++;
							column_index = 0;
						}
					}
				}
			}
		}

		/* print the right matrix as requested by the user */
		if (storage_variable == 1)
		{
			print_matrix(slot_A, current_matrix_rows, current_matrix_columns);
		}
		else if (storage_variable == 2)
		{
			print_matrix(slot_B, current_matrix_rows, current_matrix_columns);
		}
		else if (storage_variable == 3)
		{
			print_matrix(slot_C, current_matrix_rows, current_matrix_columns);
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
