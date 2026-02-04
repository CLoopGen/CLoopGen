#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern size_t j;
extern size_t incX;
extern size_t incY;
extern size_t lenY;
extern double *X;
extern double *Y;
extern double *Ad;
extern int *Ap;
extern int *Ai;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding extra arithmetic operations.
    // This increases FLOPs per memory access, enhancing computational intensity.
    for (j = 0; j < lenY; ++j) {
        size_t start = Ap[j];
        size_t end = Ap[j + 1];
        size_t remainder = (end - start) % 4;
        size_t limit = start + remainder;

        // Handle unaligned or small cases with scalar loop
        if (end - start < 4) {
            for (p = start; p < end; ++p) {
                double temp = alpha * Ad[p] * X[Ai[p] * incX];
                Y[j * incY] += temp * temp + temp;  // Extra computation: square and add
            }
        } else {
            // Unroll by 4 to increase ILP and arithmetic density
            for (p = start; p < limit; ++p) {
                double temp = alpha * Ad[p] * X[Ai[p] * incX];
                Y[j * incY] += temp * temp + temp;
            }
            for (; p + 3 < end; p += 4) {
                double temp1 = alpha * Ad[p] * X[Ai[p] * incX];
                double temp2 = alpha * Ad[p+1] * X[Ai[p+1] * incX];
                double temp3 = alpha * Ad[p+2] * X[Ai[p+2] * incX];
                double temp4 = alpha * Ad[p+3] * X[Ai[p+3] * incX];

                Y[j * incY] += (temp1 * temp1 + temp2 * temp2) + (temp3 * temp3 + temp4 * temp4);
                Y[j * incY] += temp1 + temp2 + temp3 + temp4;
            }
            // Cleanup
            for (; p < end; ++p) {
                double temp = alpha * Ad[p] * X[Ai[p] * incX];
                Y[j * incY] += temp * temp + temp;
            }
        }
    }
}
