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
    for (j = 0; j < lenY; ++j) {
        if (Ap[j] >= Ap[j + 1]) continue;
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            if (Ad[p] == 0.0) continue;
            Y[j * incY] += alpha * Ad[p] * X[Ai[p] * incX];
        }
    }
}
