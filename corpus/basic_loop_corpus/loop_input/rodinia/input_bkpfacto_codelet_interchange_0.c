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

void init_vars() {
    i = 1024;  // Set i to a reasonable size for ~0.01s runtime
    j = 512;   // Ensure j is within valid range [0, i)
    k = 0;     // Initialized in loop, but set here for completeness

    A = (MAT*)calloc(1, sizeof(MAT));
    A->m = i;
    A->n = i;
    A->max_m = i;
    A->max_n = i;
    A->max_size = i * i;
    
    A->base = (double*)calloc(i * i, sizeof(double));
    A->me = (double**)calloc(i, sizeof(double*));
    
    for (int idx = 0; idx < i; idx++) {
        A->me[idx] = &(A->base[idx * i]);
    }

    // Initialize matrix elements to avoid undefined behavior
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < i; col++) {
            A->me[row][col] = (double)(row * i + col);
        }
    }
}