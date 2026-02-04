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

int j;
MAT *Q;
MAT *H1;

void init_vars() {
    const size_t mat_size = 16384; // Adjusted size for ~0.01 sec runtime

    // Allocate Q and H1 structures
    Q = (MAT*)malloc(sizeof(MAT));
    H1 = (MAT*)malloc(sizeof(MAT));

    // Initialize dimensions
    Q->m = mat_size;
    Q->n = mat_size;
    Q->max_m = mat_size;
    Q->max_n = mat_size;
    Q->max_size = mat_size;

    H1->m = mat_size;
    H1->n = mat_size;
    H1->max_m = mat_size;
    H1->max_n = mat_size;
    H1->max_size = mat_size;

    // Allocate base arrays
    Q->base = (double*)calloc(mat_size * mat_size, sizeof(double));
    H1->base = (double*)calloc(mat_size * mat_size, sizeof(double));

    // Allocate row pointers
    Q->me = (double**)malloc(mat_size * sizeof(double*));
    H1->me = (double**)malloc(mat_size * sizeof(double*));

    // Point each row pointer to the correct location in the base array
    for (size_t i = 0; i < mat_size; i++) {
        Q->me[i] = &(Q->base[i * mat_size]);
        H1->me[i] = &(H1->base[i * mat_size]);
    }

    // Ensure H1->me[j][j] access is valid for j in [0, Q->m)
    // Since Q->m == mat_size and H1->me has mat_size rows and columns, it's safe
}