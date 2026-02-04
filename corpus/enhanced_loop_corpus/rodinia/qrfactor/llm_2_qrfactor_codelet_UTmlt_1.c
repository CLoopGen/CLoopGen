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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *U;
extern VEC *x;
extern VEC *out;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the computation order
    // Instead of accessing U->me[j][i] (column-major like in inner loop), we reorganize to access consecutive memory locations.
    // We precompute a transposed view or access by rows after restructuring the summation logic.
    double *temp_sum = (double*)calloc(limit, sizeof(double));
    if (!temp_sum) return;

    for (j = 0; j < limit; j++) {
        double *u_row = U->me[j];
        double x_val = x->ve[j];
        for (i = j; i < limit; i++) {
            temp_sum[i] += u_row[i] * x_val;
        }
    }

    for (i = 0; i < limit; i++) {
        out->ve[i] = temp_sum[i];
    }

    free(temp_sum);
}
