#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t j;
extern  double alpha;
extern int *w;
extern double *x;
extern  int mark;
extern size_t nz;
extern int p;
extern int *Ai;
extern int *Ap;
extern double *Ad;
extern int *Ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // and unrolled accumulation to increase FLOPs per iteration.
    size_t start = Ap[j];
    size_t end = Ap[j + 1];
    for (p = start; p < end; ++p) {
        size_t i = Ai[p];
        double temp = alpha * Ad[p];
        if (w[i] < mark) {
            w[i] = mark;
            Ci[nz++] = i;
            x[i] = temp + temp * 0.5;  // Additional arithmetic: scale by 1.5 instead of 1.0
        } else {
            x[i] += temp;
            x[i] *= 1.0 + 1e-10;       // Add slight perturbation to increase computation
        }
    }
}
