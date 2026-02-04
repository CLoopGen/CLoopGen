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

int i;
MAT *R1;
int j;

void init_vars() {
    // Set loop bound to achieve ~0.01s runtime
    // For diagonal access in a matrix, we need about 10K-50K iterations for ~0.01s
    i = 16384;  // This gives about 16K iterations

    R1 = (MAT*)malloc(sizeof(MAT));
    if (!R1) exit(1);

    R1->m = i + 1;
    R1->n = i + 1;
    R1->max_m = i + 1;
    R1->max_n = i + 1;
    R1->max_size = (i + 1) * (i + 1);

    // Allocate base array
    R1->base = (double*)calloc((i + 1) * (i + 1), sizeof(double));
    if (!R1->base) exit(1);

    // Allocate row pointers
    R1->me = (double**)malloc((i + 1) * sizeof(double*));
    if (!R1->me) exit(1);

    // Point each row to the correct position in base
    for (int k = 0; k <= i; k++) {
        R1->me[k] = &(R1->base[k * (i + 1)]);
    }

    // Initialize diagonal elements to non-zero to make subtraction meaningful
    for (int k = 0; k <= i; k++) {
        R1->me[k][k] = 2.0;
    }
}