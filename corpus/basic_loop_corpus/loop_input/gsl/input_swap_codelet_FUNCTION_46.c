#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the double loop takes about 0.01 seconds
    // The loop has approximately (K^2)/2 iterations.
    // On a modern CPU, each iteration is a few cycles; assume we can do ~1e8 iterations per second.
    // For 0.01 seconds, we want about 1e6 iterations -> K^2 / 2 = 1e6 -> K ≈ sqrt(2e6) ≈ 1414
    K = 1414;
}