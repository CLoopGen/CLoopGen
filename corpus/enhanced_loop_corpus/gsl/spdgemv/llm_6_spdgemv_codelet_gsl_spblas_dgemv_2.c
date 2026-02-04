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
    double temp = 0.0;
    for (j = 0; j < lenX; ++j) {
        temp = 0.0; // Introduce temporary accumulation to modify RAW/WAW dependencies
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            temp += Ad[p] * X[j * incX]; // Remove direct write to Y, accumulate locally first (eliminates loop-carried WAW/RW on Y)
        }
        Y[Ai[Ap[j]] * incY] += alpha * temp; // Single write per j, introducing dependency on Ai[Ap[j]]
    }
}
