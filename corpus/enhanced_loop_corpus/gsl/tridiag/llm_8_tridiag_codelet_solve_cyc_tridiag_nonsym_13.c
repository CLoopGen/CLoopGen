#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double abovediag[];
extern size_t a_stride;
extern double x[];
extern size_t x_stride;
extern size_t N;
extern double *alpha;
extern double *zb;
extern double *zu;
extern double *w;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Loop unrolling by factor of 2 to increase arithmetic per iteration and reduce loop overhead
    size_t limit = (N - 2) / 2;
    for (i = N - 2, j = 0; j <= limit; j++, i -= 2) {
        // First iteration of unroll
        if (i >= 1) {
            w[i] = (zu[i] - abovediag[a_stride * i] * w[i + 1]) / alpha[i];
            x[i * x_stride] = (zb[i] - abovediag[a_stride * i] * x[x_stride * (i + 1)]) / alpha[i];
        }
        // Second iteration of unroll
        if (i > 1) {
            w[i-1] = (zu[i-1] - abovediag[a_stride * (i-1)] * w[i]) / alpha[i-1];
            x[(i-1) * x_stride] = (zb[i-1] - abovediag[a_stride * (i-1)] * x[x_stride * i]) / alpha[i-1];
        }
    }
}
