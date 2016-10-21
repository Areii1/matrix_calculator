#define MAX_ROWS 9
#define MAX_COLUMNS 9

void add_matrices(double* A[], double* B[], double* destination[]);

void substract_matrices(double* A[], double* B[], double* destination[]);

void multiply_matrices(double* A[], double* B[], double* destination[]);

double dot_product(double* a[], double* b[], int y, int x);

void print_vector(double* C[], int y, int x, int a_or_b);

void transpose_matrix(double* A[], double* C[]);

void gaussian_elimination(double* matrix[], double* destination_matrix[], int rows, int columns);

void organize_matrix(double* matrix[], double* destination_matrix[], int rows, int columns);

void get_leading_zeros_table(double* matrix[], int rows, int columns);

void swap_rows(double* matrix[], double* destination_matrix[], int a, int b,
		int rows, int columns);
