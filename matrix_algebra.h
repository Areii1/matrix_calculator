#define MAX_ROWS 10
#define MAX_COLUMNS 10

void add_matrices(int* A[], int* B[], int* destination[]);

void substract_matrices(int* A[], int* B[], int* destination[]);

void multiply_matrices(int* A[], int* B[], int* destination[]);

int dot_product(int* a[], int* b[], int y, int x);

void print_vector(int* C[], int y, int x, int a_or_b);

void transpose_matrix(int* C[], int* destination_matrix[]);
