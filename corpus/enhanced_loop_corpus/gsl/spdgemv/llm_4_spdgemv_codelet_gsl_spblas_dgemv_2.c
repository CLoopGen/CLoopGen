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
        if (Ap[j] >= Ap[j + 1]) continue;
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            if (Ai[p] == -1) continue;
            Y[Ai[p] * incY] += alpha * Ad[p] * X[j * incX];
        }
    }
}
