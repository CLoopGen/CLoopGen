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

extern MAT *A;
extern int k;
extern int _usr_j0;
extern double beta;
extern double nu1;
extern double nu2;
extern double nu3;
extern double ip;
extern double prod;
extern int j;
extern int n;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 1: Strided Memory Access (stride of 2, unrolled by 2 with remainder handling)
    int stride = 2;
    int limit = j0 + ((n - j0) / stride) * stride; // Round down to nearest multiple of stride

    for (j = j0; j < limit; j += stride) {
        // Process two elements per iteration with strided access
        double ip0 = nu1 * ((A)->me[k][j]) + nu2 * ((A)->me[k + 1][j]) + nu3 * ((A)->me[k + 2][j]);
        double ip1 = nu1 * ((A)->me[k][j + 1]) + nu2 * ((A)->me[k + 1][j + 1]) + nu3 * ((A)->me[k + 2][j + 1]);

        double prod0 = ip0 * beta;
        double prod1 = ip1 * beta;

        ((A)->me[k][j] += (-prod0 * nu1));
        ((A)->me[k + 1][j] += (-prod0 * nu2));
        ((A)->me[k + 2][j] += (-prod0 * nu3));

        ((A)->me[k][j + 1] += (-prod1 * nu1));
        ((A)->me[k + 1][j + 1] += (-prod1 * nu2));
        ((A)->me[k + 2][j + 1] += (-prod1 * nu3));
    }

    // Handle remaining element if any
    for (; j < n; j++) {
        ip = nu1 * ((A)->me[k][j]) + nu2 * ((A)->me[k + 1][j]) + nu3 * ((A)->me[k + 2][j]);
        prod = ip * beta;
        ((A)->me[k][j] += (-prod * nu1));
        ((A)->me[k + 1][j] += (-prod * nu2));
        ((A)->me[k + 2][j] += (-prod * nu3));
    }
}
