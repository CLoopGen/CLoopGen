#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *A;
extern  int lda;
extern double *X;
extern  int incX;
extern  int nonunit;
extern int ix;
extern int jx;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via `ix` and `jx`, reindex X using consecutive indices.
    // We assume incX is positive and use direct indexing with scaling.
    for (i = N - 1; i > 0 && i--;) {
        double tmp = X[i * incX];
        int kx = (i + 1) * incX;
        for (j = i + 1; j < N; j++) {
            const double Aji = A[lda * j + i];
            tmp -= Aji * X[kx];
            kx += incX;
        }
        if (nonunit) {
            X[i * incX] = tmp / A[lda * i + i];
        } else {
            X[i * incX] = tmp;
        }
    }
}
