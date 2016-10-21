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
void complete_matrix(int* matrix[], int chosen_variable, 
		char* assigned_matrix_identifier);

int build_matrix(int* matrix[]);
void print_matrix(int* matrix[], int rows, int columns);
void malloc_matrix(int*** matrix);
void free_matrix_space(int** matrix);

/* file handling related functions */
void write_matrix_to_file(int* matrix[], char* assigned_matrix_identifier,
		int rows, int columns);

void read_matrix_from_file_into_variable(char* searched_matrix_identifier, 
		int chosen_variable);

void clear_matrix_file(void);
void print_all_matrices_in_file_format(void);
void print_matrix_by_name(int* matrix[]);

/* user related functions */
void input_matrix_measures(int chosen_variable);
void input_matrix_identifier(char* assigned_matrix_identifier);

int count_line_length(char* line);

static int A_rows, A_columns, B_rows, B_columns, C_rows, C_columns;
static int extra_rows, extra_columns;
static int chosen_variable_rows, chosen_variable_columns;
static int **slot_A;
static int **slot_B;
static int **slot_C;
static int **slot_extra;

int main(void)
{	
	int user_choice;
	int user_choice_layer_2;
	int user_choice_layer_3;

	static int chosen_variable;

	static char searched_matrix_identifier[1];
	static char assigned_matrix_identifier[1];

	malloc_matrix(&slot_A);
	malloc_matrix(&slot_B);
	malloc_matrix(&slot_C);
	malloc_matrix(&slot_extra);

	do 
	{
		printf("------------------------ USER OPTIONS ------------------------\n");
		printf("enter a matrix = '1'\n");
		printf("give a statement = '2'\n");
		printf("read a matrix by name, into a variable = '3'\n");
		printf("perform operations on the given matrices = '4'\n");
		printf("print options = '7'\n");
		printf("delete options = '8'\n");
		printf("exit program = '9'\n");
		printf("--------------------------------------------------------------\n");
		

		scanf("%d", &user_choice);
		switch (user_choice)
		{
			case 1:
				printf("which slot to use? 'A' = 1, 'B' = 2, 'C' = 3\n");
				scanf("%d", &chosen_variable);
		
				if (chosen_variable == 1)
				{
					complete_matrix(slot_A, chosen_variable, assigned_matrix_identifier);
				}
				else if (chosen_variable == 2)
				{
					complete_matrix(slot_B, chosen_variable, assigned_matrix_identifier);
				}
				else if (chosen_variable == 3)
				{
					complete_matrix(slot_C, chosen_variable, assigned_matrix_identifier);
				}

				break;

			case 2:
				printf("can't do that shit yet\n");
				break;

			case 3:

				printf("variable name to search?\n");
				scanf("%s", searched_matrix_identifier);

				printf("which slot to use? 'A' = 1, 'B' = 2, 'C' = 3\n");
				scanf("%d", &chosen_variable);

				read_matrix_from_file_into_variable(searched_matrix_identifier, 
						chosen_variable);
				break;

			case 4:

				printf("----------------------- ALGEBRA NOTICE -------------------\n");
				printf("A_slot matrix is the first operand, B_slot matrix is the second operand, C_slot is for the destination\n\n");

				printf("----------------------- ALGEBRA OPTIONS ------------------\n");
				printf("add matrices = '1'\n");
				printf("substract matrices = '2'\n");
				printf("multiply matrices = '3'\n");
				printf("transpose slot_A matrix = '4'\n");
				printf("apply gaussian elimination on slot_A matrix = '5'\n");
				printf("----------------------------------------------------------\n");
				
				scanf("%d", &user_choice_layer_2);
				
				//check for matrix measure legality for certain operations
				if (((user_choice_layer_2 == 1 || user_choice_layer_2 == 2)
						&& (A_rows == B_rows && A_columns == B_columns))
						|| (user_choice_layer_2 == 3 && A_columns == B_rows)
						|| (user_choice_layer_2 == 4)
						|| (user_choice_layer_2 == 5))
				{
				//execute the process determinde by user_choice

					int user_choice;
					int choice_conflict = 0;

					switch (user_choice_layer_2)
					{
						case 1:
							C_rows = A_rows;
							C_columns = A_columns;

							add_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, C_rows, C_columns);

							input_matrix_identifier(assigned_matrix_identifier);
							write_matrix_to_file(slot_C, assigned_matrix_identifier, C_rows,
									C_columns);

							break;

						case 2:
							C_rows = A_rows;
							C_columns = A_columns;

							substract_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, C_rows, C_columns);
							
							input_matrix_identifier(assigned_matrix_identifier);
							write_matrix_to_file(slot_C, assigned_matrix_identifier, C_rows, 
									C_columns);
							break;

						case 3:
							C_rows = A_rows;
							C_columns = B_columns;

							multiply_matrices(slot_A, slot_B, slot_C);
							print_matrix(slot_C, C_rows, C_columns);

							input_matrix_identifier(assigned_matrix_identifier);
							write_matrix_to_file(slot_C, assigned_matrix_identifier, C_rows,
									C_columns);
							
							break;

						case 4:
							printf("transpose slot_A = 1, slot_B = 2\n");

							do
							{
								scanf("%d", &user_choice_layer_3);
								
								if (user_choice_layer_3 == 1)
								{
									C_rows = A_columns;
									C_columns = A_rows;

									transpose_matrix(slot_A, slot_C);
									print_matrix(slot_C, A_columns, A_rows);
									choice_conflict = 0;
								}
								else if (user_choice_layer_3 == 2)
								{
									C_rows = B_columns;
									C_columns = B_rows;

									transpose_matrix(slot_B, slot_C);
									print_matrix(slot_C, C_rows, C_columns);
									choice_conflict = 0;
								}
								else
								{
									printf("did not recognize '%d', slot_A = 1, slot_B = 2\n", 
											user_choice_layer_3);
									choice_conflict = 1;
								}
							} while (choice_conflict == 1);
							break;

						case 5:
							C_rows = A_rows;
							C_columns = A_columns;

							gaussian_elimination(slot_A, slot_C, A_rows, A_columns);
							printf("destination matrix inside main.c\n");
							print_matrix(slot_C, C_rows, C_columns);

							break;

						default:
							printf("user value not regonized\n");
							break;


					}	
				}
				else
				{
					printf("measures do not support the user suggested operation\n");
				}

				break;

			case 7:

	
				printf("--------------------- PRINT OPTIONS ----------------------\n");
				printf("print a matrix by name from file = '1'\n");
				printf("print all matrices in file format = '2'\n");
				printf("print all matrices in currently existing variables = '3'\n");
				printf("----------------------------------------------------------\n");
	
				scanf("%d", &user_choice_layer_2);
			
				if (user_choice_layer_2 == 1)
				{
					printf("provide name of the matrix\n");
					scanf("%s", searched_matrix_identifier);
					read_matrix_from_file_into_variable(searched_matrix_identifier, 4);
					print_matrix(slot_extra, extra_rows, extra_columns);
				}
				else if (user_choice_layer_2 ==  2)
				{
					print_all_matrices_in_file_format();
				}
				else if (user_choice_layer_2 == 3)
				{
					printf("MATRIX A\n\n");
					print_matrix(slot_A, A_rows, A_columns);
					printf("MATRIX B\n\n");
					print_matrix(slot_B, B_rows, B_columns);
					printf("MATRIX C\n\n");
					print_matrix(slot_C, C_rows, C_columns);
				}

				break;

			case 8:
				
				printf("------------------- DELETE OPTIONS -----------------------\n");
				printf("delete a matrix by name from file = '1'\n");
				printf("delete all matrices from file = '2'\n");
				printf("----------------------------------------------------------\n");
				
				scanf("%d", &user_choice_layer_2);
				
				if (user_choice_layer_2 == 2)
				{
					clear_matrix_file();	
				}

				break;

			case 9:
				break;

			default:
				printf("value ('%d') not recognized\n", user_choice);
		}
	} while (user_choice != 9);

	free_matrix_space(slot_A);
	free_matrix_space(slot_B);
	free_matrix_space(slot_C);
	free_matrix_space(slot_extra);
	
	return 0;
}

void complete_matrix(int* matrix[], int chosen_variable,
		char* assigned_matrix_identifier)
{
		input_matrix_measures(chosen_variable);
		build_matrix(matrix);
		print_matrix(matrix, chosen_variable_rows, chosen_variable_columns);
		input_matrix_identifier(assigned_matrix_identifier);
		write_matrix_to_file(matrix, assigned_matrix_identifier, 
				chosen_variable_rows,	chosen_variable_columns);
}

int build_matrix(int* matrix[])
{
	int x, y;

	for (y = 0; y < chosen_variable_rows; y++)
	{
		for (x = 0; x < chosen_variable_columns; x++)
		{

				printf("element [%d,%d]: ", y, x);
				scanf("%d", &matrix[y][x]);
		}
	}
	return 0;
}

void print_matrix(int* matrix[], int rows, int columns)
{
	int y, x;	
	
	printf("________________________________________________________________\n");
	for (y = 0; y < rows; y++)
	{
		printf("\n");
		for (x = 0; x < columns; x++)
		{
			printf("%d\t", matrix[y][x]);
		}
		printf("\n");
	}
	printf("______________________________________________________________\n\n");
}

void print_matrix_by_name(int* matrix[])
{

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

void free_matrix_space(int** matrix)
{
	int i;

	for (i = 0; i < MAX_ROWS; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
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


void print_all_matrices_in_file_format(void)
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

void write_matrix_to_file(int* matrix[], char* assigned_matrix_identifier,
		int rows, int columns)
{
	FILE *fp;
	fp = fopen(FILENAME, "a");
	
	fflush(fp);
	fprintf(fp, "<%s>", assigned_matrix_identifier);
	fprintf(fp, "(%d,%d)=", rows, columns);
	int x, y;

	fputs("{", fp);
	for (y = 0; y < rows; y++)
	{
		fputs("{", fp);
		for (x = 0; x < columns; x++)
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

void input_matrix_identifier(char* assigned_matrix_identifier)
{
	printf("give a one character long name for the matrix\n");
	scanf("%s", assigned_matrix_identifier);
}

/* search matrix by name from matrix.txt file and read it to a variable
in the program (slot_A or slot_B or slot_C).
*/
void read_matrix_from_file_into_variable(char* searched_matrix_identifier,
		int chosen_variable)
{
	char searched_variable_char = searched_matrix_identifier[0];

	FILE *fp;
	fp = fopen(FILENAME, "r");
	char line[MAXSTRLEN];

	int current_matrix_rows = 0;
	int current_matrix_columns = 0;
	
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
						if (chosen_variable == 1)
						{									
							slot_A[row_index][column_index] = current_number;
						}
						else if (chosen_variable == 2)
						{
							slot_B[row_index][column_index] = current_number;
						}
						else if (chosen_variable == 3)
						{
							slot_C[row_index][column_index] = current_number;
						}
						else if (chosen_variable == 4)
						{
							slot_extra[row_index][column_index] = current_number;
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
		if (chosen_variable == 1)
		{
			A_rows = current_matrix_rows;
			A_columns = current_matrix_columns;
			print_matrix(slot_A, current_matrix_rows, current_matrix_columns);
		}
		else if (chosen_variable == 2)
		{
			B_rows = current_matrix_rows;
			B_columns = current_matrix_columns;
			print_matrix(slot_B, current_matrix_rows, current_matrix_columns);
		}
		else if (chosen_variable == 3)
		{
			C_rows = current_matrix_rows;
			C_columns = current_matrix_columns;
			print_matrix(slot_C, current_matrix_rows, current_matrix_columns);
		}
		else if (chosen_variable == 4)
		{
			extra_rows = current_matrix_rows;
			extra_columns = current_matrix_columns;
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



