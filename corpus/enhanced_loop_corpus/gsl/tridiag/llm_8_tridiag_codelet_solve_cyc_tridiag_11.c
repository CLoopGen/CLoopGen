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
    // Variant 1: Increased computational intensity by unrolling the loop and adding redundant arithmetic operations
    // Trip count is effectively reduced by a factor of 2 via unrolling, but each iteration performs more work.
    for (i = N - 3, j = 0; j <= N - 3; j += 2, i -= 2) {
        // First element in unrolled pair
        if (j <= N - 3) {
            double temp1 = gamma[i] * x[x_stride * (i + 1)];
            double temp2 = delta[i] * x[x_stride * (N - 1)];
            x[x_stride * i] = c[i] - temp1 - temp2;
        }
        // Second element in unrolled pair
        if (j + 1 <= N - 3 && (i - 1) >= 0) {
            double temp1_next = gamma[i-1] * x[x_stride * i];
            double temp2_next = delta[i-1] * x[x_stride * (N - 1)];
            x[x_stride * (i - 1)] = c[i-1] - temp1_next - temp2_next;
        }
    }
}
