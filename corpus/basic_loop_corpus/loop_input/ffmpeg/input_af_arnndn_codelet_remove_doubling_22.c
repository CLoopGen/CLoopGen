#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
int maxperiod;
int N;
int i;
float yy;
float yy_lookup[769];

void init_vars() {
    N = 1 << 20; // 1 million elements, approx 4MB for float array
    maxperiod = 768; // Must be <= 768 to fit in yy_lookup[769] and avoid out-of-bounds
    x = (float*)aligned_alloc(32, (N + maxperiod) * sizeof(float)); // Allocate extra before start and after end

    if (!x) {
        exit(1);
    }

    // Initialize the entire buffer to a small positive value to prevent NaNs or extreme values
    for (int idx = 0; idx < N + maxperiod; idx++) {
        x[idx] = 0.1f;
    }

    // Adjust base pointer so that x[-i] accesses valid memory for i in [1, maxperiod]
    x += maxperiod;

    yy = 0.0f;

    // Initialize yy_lookup with zeros
    for (int idx = 0; idx < 769; idx++) {
        yy_lookup[idx] = 0.0f;
    }
}