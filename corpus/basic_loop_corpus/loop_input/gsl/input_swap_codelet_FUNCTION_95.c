#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the double loop takes about 0.01 seconds
    // The number of iterations is roughly (K^2)/2.
    // On a modern CPU, we assume ~1e9 iterations per second, so for 0.01s we want ~1e7 iterations.
    // Solve: K^2 / 2 ≈ 10,000,000  => K ≈ sqrt(20,000,000) ≈ 4472
    K = 4472;
}