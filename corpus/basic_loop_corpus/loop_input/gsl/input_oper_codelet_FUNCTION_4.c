#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
size_t N;
size_t tda;
size_t i;
size_t j;

void init_vars() {
    // Aim for approximately 0.01 seconds of computation
    // The loop performs M * N iterations with simple arithmetic
    // On a modern CPU, ~1e8 operations take roughly 0.1 seconds,
    // so we target ~1e6 to ~2e6 iterations for 0.01 seconds.

    M = 1000;
    N = 1000;
    tda = N;  // typical stride for a row-major matrix

    // 'aij' is computed as 2*(i*tda + j), which resembles a linear index
    // No actual array is accessed in the provided loop, so no allocation needed.
    // Only ensure that i and j stay within bounds, which they do via loop conditions.
}