#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t i;
double fval[25];
double v[12];

void init_vars() {
    // Initialize fval with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 25; idx++) {
        fval[idx] = (double)(idx + 1) * 1.5;
    }
    // Initialize v to zero
    for (int idx = 0; idx < 12; idx++) {
        v[idx] = 0.0;
    }
    // Ensure loop bounds are safe: i from 0 to 11, j = 24 - i -> j from 24 down to 13, all within [0,24]
    // No out-of-bounds access for fval[i] or fval[j] when i in [0,11]
}