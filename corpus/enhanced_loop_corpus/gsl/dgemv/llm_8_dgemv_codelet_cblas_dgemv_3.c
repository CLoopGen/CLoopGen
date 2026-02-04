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
    // Variant 1: Increased computational intensity by unrolling the inner loop by a factor of 2
    // This reduces loop overhead and increases arithmetic operations per iteration
    for (j = 0; j < lenX; j++) {
        const double temp = alpha * X[ix];
        if (temp != 0.) {
            int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
            i = 0;
            // Unroll by 2: process two elements per iteration
            for (; i < lenY - 1; i += 2) {
                Y[iy] += temp * A[lda * j + i];
                Y[iy + incY] += temp * A[lda * j + i + 1];
                iy += 2 * incY;
            }
            // Handle remaining element if lenY is odd
            if (i < lenY) {
                Y[iy] += temp * A[lda * j + i];
            }
        }
        ix += incX;
    }
}
