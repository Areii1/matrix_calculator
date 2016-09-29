#define MAX_ROWS 5
#define MAX_COLUMNS 5

void add_matrices(int* A[], int* B[], int* destination[]);
void substract_matrices(int* A[], int* B[], int* destination[]);
void multiply_matrices(int* A[], int* B[], int* destination[]);
int dot_product(int u[MAX_COLUMNS], int v[MAX_ROWS]);