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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Arrays are accessed in a strided pattern: i, i+2, etc.
    size_t stride = 2;
    size_t limit = K - (K % stride); // Make sure we don't go out of bounds

    for (i = 0; i < limit; i += stride) {
        // First element in the unrolled pair
        f = (g->F)[i];
        f = K * f - i;
        if (i == k) {
            p += f;
        } else if (k == (g->A)[i]) {
            p += 1. - f;
        }

        // Second element in the unrolled pair
        if (i + 1 < K) {
            f = (g->F)[i + 1];
            f = K * f - (i + 1);
            if ((i + 1) == k) {
                p += f;
            } else if (k == (g->A)[i + 1]) {
                p += 1. - f;
            }
        }
    }

    // Handle any remaining element if K is odd
    if (limit < K) {
        i = K - 1;
        f = (g->F)[i];
        f = K * f - i;
        if (i == k) {
            p += f;
        } else if (k == (g->A)[i]) {
            p += 1. - f;
        }
    }
}
