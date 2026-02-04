#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[];
extern size_t x_stride;
extern size_t N;
extern double *delta;
extern double *gamma;
extern double *c;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased data dependency depth and extra arithmetic
    // Only iterate over even indices, reducing iterations by ~half while increasing per-iteration complexity
    for (i = N - 3, j = 0; j <= N - 3; j++, i--) {
        if ((j & 1) == 0) {  // Process only when j is even
            double prev_val = (i + 2 < N) ? x[x_stride * (i + 2)] : 0.0;
            double corr_term = (gamma[i] + gamma[i] * gamma[i]) * prev_val;  // Extra computation
            x[x_stride * i] = c[i] 
                            - gamma[i] * x[x_stride * (i + 1)] 
                            - delta[i] * x[x_stride * (N - 1)] 
                            + corr_term;  // Additional correction term
        }
    }
}
