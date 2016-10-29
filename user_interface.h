/* matrix building related functions */
void complete_matrix(double* matrix[], int chosen_variable, 
		char* assigned_matrix_identifier);

int build_matrix(double* matrix[]);
void print_matrix(double* matrix[], int rows, int columns);
void malloc_matrix(double*** matrix);
void free_matrix_space(double** matrix);

void generate_random_matrix(double* matrix[]);

/* file handling related functions */
void write_matrix_to_file(double* matrix[], char* assigned_matrix_identifier,
		int rows, int columns);

void read_matrix_from_file_into_variable(char* searched_matrix_identifier, 
		int chosen_variable);

void clear_matrix_file(void);
void print_all_matrices_in_file_format(void);
void print_matrix_by_name(double* matrix[]);

/* user related functions */
void input_matrix_measures(int chosen_variable);
void input_matrix_identifier(char* assigned_matrix_identifier);

int count_line_length(char* line);
