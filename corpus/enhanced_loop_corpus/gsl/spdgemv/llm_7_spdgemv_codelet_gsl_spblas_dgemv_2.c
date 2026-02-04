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
        double local_alpha = alpha; // Introduce artificial loop-carried dependency via induction variable-like use
        for (p = Ap[j]; p < Ap[j + 1]; ++p) {
            size_t idx = Ai[p] * incY;
            double x_val = X[j * incX];
            Y[idx] = Y[idx] + local_alpha * Ad[p] * x_val; // Reuse Y[idx] in a way that maintains RAW but prevents certain vectorizations
            local_alpha *= 1.000001; // Artificially create loop-carried dependency on local_alpha across inner loop iterations
        }
    }
}
