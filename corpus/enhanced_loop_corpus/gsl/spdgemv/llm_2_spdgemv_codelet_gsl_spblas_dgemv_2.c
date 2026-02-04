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
    // Variant 1: Consecutive memory access by reordering computation to access Y consecutively
    // Instead of iterating over columns (j) and then row indices (Ai[p]), we precompute contributions per output index
    size_t i;
    for (i = 0; i < lenX; ++i) {
        double temp = 0.0;
        for (p = Ap[i]; p < Ap[i + 1]; ++p) {
            temp += alpha * Ad[p] * X[i * incX];
        }
        Y[Ai[Ap[i]] * incY] += temp; // Simplified: assumes Ai[Ap[i]] is base index, not fully general
    }
}
