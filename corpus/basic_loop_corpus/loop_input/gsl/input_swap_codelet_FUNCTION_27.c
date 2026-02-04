#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the double loop takes about 0.01 seconds
    // The number of iterations is roughly (K^2)/2.
    // On a modern CPU, we assume ~1e8 operations per second for simple loops,
    // so for 0.01 seconds, we want about 1e6 total iterations.

    // Solve: K*(K-1)/2 ≈ 1e6  => K ≈ 1414
    // We choose K = 1400 to be safe.

    K = 1400;
}