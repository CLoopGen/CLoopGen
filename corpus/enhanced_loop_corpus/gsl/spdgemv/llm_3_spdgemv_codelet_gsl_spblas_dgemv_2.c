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
    // Variant 2: Strided but unrolled memory access with indirect indexing for X and Y to increase stride utilization
    // We unroll the inner loop by a factor of 2 to create more predictable strided access patterns
    size_t j_next;
    int p_next;
    for (j = 0; j + 1 < lenX; j += 2) {
        j_next = j + 1;
        for (p = Ap[j], p_next = Ap[j_next]; 
             p < Ap[j + 1] && p_next < Ap[j_next + 1]; 
             ++p, ++p_next) {
            Y[Ai[p] * incY] += alpha * Ad[p] * X[j * incX];
            Y[Ai[p_next] * incY] += alpha * Ad[p_next] * X[j_next * incX];
        }
        // Handle remaining entries in case ranges differ
        while (p < Ap[j + 1]) {
            Y[Ai[p] * incY] += alpha * Ad[p] * X[j * incX];
            ++p;
        }
        while (p_next < Ap[j_next + 1]) {
            Y[Ai[p_next] * incY] += alpha * Ad[p_next] * X[j_next * incX];
            ++p_next;
        }
    }
    // Handle odd leftover iteration
    if (j < lenX) {
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            Y[Ai[p] * incY] += alpha * Ad[p] * X[j * incX];
        }
    }
}
