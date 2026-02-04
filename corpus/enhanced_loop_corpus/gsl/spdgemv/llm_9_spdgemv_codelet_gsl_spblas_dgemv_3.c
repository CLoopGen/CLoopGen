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
    // Variant 2: Reduced trip count with increased stride and simplified arithmetic.
    // This decreases total iterations but maintains data coverage via strided access.
    // Also reduces arithmetic complexity to create a memory-bound variant.

    for (j = 0; j < lenY; j += 2) {  // Process two rows at a time, reducing outer loop iterations
        double *y_ptr = &Y[j * incY];
        if (j + 1 < lenY) {
            // Combine contributions from two consecutive j values when possible
            for (p = Ap[j]; p < Ap[j + 1]; ++p) {
                Y[j * incY] += alpha * Ad[p] * X[Ai[p] * incX];
            }
            for (p = Ap[j + 1]; p < Ap[j + 2]; ++p) {
                Y[(j + 1) * incY] += alpha * Ad[p] * X[Ai[p] * incX];
            }
        } else {
            // Handle odd-sized lenY
            for (p = Ap[j]; p < Ap[j + 1]; ++p) {
                Y[j * incY] += alpha * Ad[p] * X[Ai[p] * incX];
            }
        }
    }
}
