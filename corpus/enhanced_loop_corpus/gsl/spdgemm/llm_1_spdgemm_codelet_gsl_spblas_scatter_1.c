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
    // Variant 2: Decreased effective loop depth by unrolling the first iteration (if exists)
    // This reduces dynamic loop iterations and flattens part of the loop body
    p = Ap[j];
    if (p >= Ap[j + 1]) return; // No iterations to perform

    // Unroll first iteration
    {
        size_t i = Ai[p];
        if (w[i] < mark) {
            w[i] = mark;
            Ci[nz++] = i;
            x[i] = alpha * Ad[p];
        } else {
            x[i] += alpha * Ad[p];
        }
        ++p;
    }

    // Remaining iterations in a simpler loop
    for (; p < Ap[j + 1]; ++p) {
        size_t i = Ai[p];
        if (w[i] < mark) {
            w[i] = mark;
            Ci[nz++] = i;
            x[i] = alpha * Ad[p];
        } else {
            x[i] += alpha * Ad[p];
        }
    }
}
