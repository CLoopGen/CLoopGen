#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lenX; j++) {
    const double temp = alpha * X[j * incX];  // Changed to direct strided indexing instead of using ix
    if (temp != 0.) {
        for (i = 0; i < lenY; i++) {
            const int idx_A = j + i * lda;     // Precomputed linear index with consecutive-like stride in A
            const int idx_Y = i * incY;        // Direct indexing into Y without separate iy variable
            Y[idx_Y] += temp * A[idx_A];
        }
    }
}
}
