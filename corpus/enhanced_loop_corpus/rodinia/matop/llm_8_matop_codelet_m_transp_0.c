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

extern MAT *in;
extern MAT *out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled inner loop by factor of 2
    for (i = 0; i < in->m; i++) {
        for (j = 0; j + 1 < in->n; j += 2) {
            // Unroll two iterations: compute transpose with scaling and offset addition
            out->me[j][i] = in->me[i][j] * 1.5 + 0.1;
            out->me[j+1][i] = in->me[i][j+1] * 1.5 + 0.1;
        }
        // Handle remaining element if n is odd
        if (j < in->n) {
            out->me[j][i] = in->me[i][j] * 1.5 + 0.1;
        }
    }
}
