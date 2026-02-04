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

extern MAT *QR;
extern VEC *y;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing QR->me[j][i] and y->ve[j] consecutively in the inner loop,
    // we simulate a strided access by stepping through indices with a fixed stride.
    // Here, we use stride = 1 but reverse the order of access (backwards traversal) to modify access pattern.

    for (i = 0; i < limit; i++) {
        sum = 0.;
        // Traverse j in reverse to change memory access order (strided-like due to cache effects)
        for (j = i - 1; j >= 0; j--) {
            sum -= QR->me[j][i] * y->ve[j];
        }
        sum -= (sum < 0.) ? 1. : -1.;
        y->ve[i] = sum / QR->me[i][i];
    }
}
