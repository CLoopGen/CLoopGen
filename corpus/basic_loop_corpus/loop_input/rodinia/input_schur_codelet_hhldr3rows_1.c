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
int i0;
double beta;
double nu1;
double nu2;
double nu3;
double ip;
double prod;
int i;

void init_vars() {
    // Set constants
    beta = 0.5;
    nu1 = 1.0;
    nu2 = 0.5;
    nu3 = 0.25;
    
    // Allocate matrix data to target ~64MB of double data (~8M elements)
    size_t total_elements = 8 * 1024 * 1024;
    // Use rectangular matrix: more rows than columns for safe k+2 access
    A = (MAT*)calloc(1, sizeof(MAT));
    A->m = 8192;
    A->n = 1024;
    A->max_m = A->m;
    A->max_n = A->n;
    A->max_size = A->m * A->n;
    
    // Ensure we can access k+2 without going out of bounds
    k = 100;  // leave room for k+2
    i0 = A->m - 1;  // use all rows
    
    // Allocate base array and row pointers
    A->base = (double*)calloc(A->max_size, sizeof(double));
    A->me = (double**)calloc(A->m, sizeof(double*));
    
    // Initialize row pointers into contiguous base memory
    for (u_int row = 0; row < A->m; row++) {
        A->me[row] = &(A->base[row * A->n]);
    }
    
    // Initialize matrix with non-zero values to make computation meaningful
    for (u_int row = 0; row < A->m; row++) {
        for (u_int col = 0; col < A->n; col++) {
            A->me[row][col] = (double)(row % 100 + col % 50) / 10.0;
        }
    }
}