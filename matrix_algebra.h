#define MAX_ROWS 9
#define MAX_COLUMNS 9

void add_matrices(int* A[], int* B[], int* destination[]);

void substract_matrices(int* A[], int* B[], int* destination[]);

void multiply_matrices(int* A[], int* B[], int* destination[]);

int dot_product(int* a[], int* b[], int y, int x);

void print_vector(int* C[], int y, int x, int a_or_b);

void transpose_matrix(int* A[], int* C[]);

void gaussian_elimination(int* matrix[], int* destination_matrix[], int rows, int columns);

void organize_matrix(int* matrix[], int rows, int columns);
