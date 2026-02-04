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
int k;
int _usr_j0;
double beta;
double nu1;
double nu2;
double nu3;
double ip;
double prod;
int j;
int n;

void init_vars() {
    // Set constants
    nu1 = 0.5;
    nu2 = 0.3;
    nu3 = 0.2;
    beta = 0.1;
    k = 0;
    _usr_j0 = 0;

    // Allocate matrix data to target ~64MB of double elements (~8MB per 1M doubles)
    // We'll use a 2D array with 3 rows and many columns to ensure loop runs long enough
    size_t num_columns = 8000000;  // ~64MB for 3 rows: 3 * 8e6 * 8 bytes = ~192MB total (conservative)
    n = num_columns;

    // Allocate base storage for matrix elements
    A = (MAT*)calloc(1, sizeof(MAT));
    A->m = 3;
    A->n = n;
    A->max_m = 3;
    A->max_n = n;
    A->max_size = 3 * n;
    
    // Allocate base array
    A->base = (double*)calloc(n * 3, sizeof(double));
    
    // Allocate row pointers
    A->me = (double**)calloc(3, sizeof(double*));
    A->me[0] = A->base;
    A->me[1] = A->base + n;
    A->me[2] = A->base + 2 * n;

    // Initialize matrix elements to prevent NaN/inf issues
    for (size_t i = 0; i < 3 * n; i++) {
        A->base[i] = 1.0 + (i % 7) * 0.1;
    }

    // Ensure k+2 is valid
    k = 0;
}