#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t K;
    size_t *A;
    double *F;
} gsl_ran_discrete_t;

extern size_t k;
extern  gsl_ran_discrete_t *g;
extern size_t i;
extern size_t K;
extern double f;
extern double p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (gather-style) memory access using reversed index mapping
    // Access arrays in reverse order (from K-1 down to 0), creating a different access pattern
    for (i = K; i > 0; ) {
        --i; // Decrement first to avoid overflow
        size_t rev_i = K - 1 - i; // Reverse index: last becomes first, etc.

        f = (g->F)[rev_i];
        f = K * f - rev_i;

        if (rev_i == k) {
            p += f;
        } else if (k == (g->A)[rev_i]) {
            p += 1. - f;
        }
    }
}
