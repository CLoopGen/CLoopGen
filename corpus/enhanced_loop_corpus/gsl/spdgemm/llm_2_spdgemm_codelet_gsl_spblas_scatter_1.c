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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing Ai[p], Ad[p] consecutively, access them with a fixed stride (e.g., stride of 2)
    // To maintain correctness, we simulate the same logical behavior by unrolling and adjusting bounds
    size_t start = Ap[j];
    size_t end = Ap[j + 1];
    size_t p_even, p_odd;

    // Process pairs of indices to simulate strided-like pattern while covering all elements
    for (p_even = start; p_even < end; p_even += 2) {
        size_t i = Ai[p_even];
        if (w[i] < mark) {
            w[i] = mark;
            Ci[nz++] = i;
            x[i] = alpha * Ad[p_even];
        } else {
            x[i] += alpha * Ad[p_even];
        }

        p_odd = p_even + 1;
        if (p_odd < end) {
            size_t j = Ai[p_odd];
            if (w[j] < mark) {
                w[j] = mark;
                Ci[nz++] = j;
                x[j] = alpha * Ad[p_odd];
            } else {
                x[j] += alpha * Ad[p_odd];
            }
        }
    }
}
