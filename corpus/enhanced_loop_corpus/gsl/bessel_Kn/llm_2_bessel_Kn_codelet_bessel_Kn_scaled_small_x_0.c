#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using an array-like stride in computation
    // Though no explicit array is used, we simulate strided behavior by updating k in steps,
    // and adjusting the loop body accordingly to maintain correctness.
    // Here, we use a stride of 2 for k, unrolling the effect of two iterations at once.

    int stride = 2;
    int k_limit = n - 1;

    // Handle odd n-1 by ensuring we don't exceed bounds
    for (k = 1; k <= k_limit; k += stride) {
        // First iteration of the stride
        k_term *= -y / (k * (n - k));
        sum1 += k_term;

        // Second part of the stride, if within bounds
        if (k + 1 <= k_limit) {
            k_term *= -y / ((k + 1) * (n - (k + 1)));
            sum1 += k_term;
        }
    }
}
