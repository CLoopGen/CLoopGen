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
    size_t j;
    for (j = 0; j < lenY; ++j) {
        size_t p_start = Ap[j];
        size_t p_end = Ap[j + 1];
        size_t p;
        for (p = p_start; p < p_end; ++p) {
            Y[j * incY] += alpha * Ad[p] * X[Ai[p] * incX];
        }
    }
}
