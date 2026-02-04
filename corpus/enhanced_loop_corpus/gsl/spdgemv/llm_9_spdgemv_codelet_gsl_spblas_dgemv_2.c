#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern size_t j;
extern size_t incX;
extern size_t incY;
extern size_t lenX;
extern double *X;
extern double *Y;
extern double *Ad;
extern int *Ap;
extern int *Ai;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via outer loop stride and simplified inner condition with fused bounds check
    for (j = 0; j < lenX; j += 2) {  // Process every second element to reduce outer iterations
        size_t start = Ap[j];
        size_t next_start = (j + 1 < lenX) ? Ap[j + 1] : start;
        size_t end = (j + 1 < lenX) ? Ap[j + 2] : start;  // Safe bound for even-sized arrays

        // Merge contributions from two consecutive j indices if possible
        for (p = start; p < next_start; ++p) {
            Y[Ai[p] * incY] += alpha * Ad[p] * X[j * incX];  // j-th contribution
        }
        if (j + 1 < lenX) {
            for (p = next_start; p < end; ++p) {
                Y[Ai[p] * incY] += alpha * Ad[p] * X[(j + 1) * incX];  // (j+1)-th contribution
            }
        }
    }
}
