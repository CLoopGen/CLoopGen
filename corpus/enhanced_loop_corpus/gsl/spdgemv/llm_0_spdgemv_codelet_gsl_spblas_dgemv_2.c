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
    for (j = 0; j < lenX; ++j) {
        size_t start = Ap[j];
        size_t end = Ap[j + 1];
        for (p = start; p < end; ++p) {
            size_t indexY = Ai[p] * incY;
            double temp = alpha * Ad[p] * X[j * incX];
            Y[indexY] += temp;
        }
    }
}
