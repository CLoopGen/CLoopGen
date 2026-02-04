#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

MAT *A;
int i;
int j;
double tmp;
int k;
int n;

void init_vars() {
    // Set matrix dimensions to ensure sufficient data size (~64MB of doubles)
    const size_t total_data_size = 16 * 1024 * 1024; // ~128MB of double elements
    const size_t avg_row_size = 2048;
    const size_t num_rows = total_data_size / avg_row_size;

    A = (MAT *)calloc(1, sizeof(MAT));
    A->m = num_rows;
    A->n = avg_row_size;
    A->max_m = num_rows;
    A->max_n = avg_row_size;
    A->max_size = total_data_size;
    
    A->base = (double *)calloc(total_data_size, sizeof(double));
    A->me = (double **)calloc(num_rows, sizeof(double *));
    
    for (u_int row = 0; row < num_rows; ++row) {
        A->me[row] = &(A->base[row * avg_row_size]);
        // Initialize with non-zero values to make swapping observable
        for (u_int col = 0; col < avg_row_size; ++col) {
            A->me[row][col] = (double)(row * avg_row_size + col);
        }
    }

    // Set loop indices: ensure j+1 < n and i < n, and both i,j are valid rows
    j = 0;
    i = 1;
    n = avg_row_size;  // column count for loop bound

    tmp = 0.0;
    k = 0;
}