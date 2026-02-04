#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // To make the loop runtime approximately 0.01 seconds,
    // we estimate that the inner loop runs about O(K^2) times.
    // On a modern CPU, ~1e8 operations per second -> ~1e6 operations in 0.01s.
    // So we set K such that K*(K-1)/2 ≈ 500000 -> K ≈ 1000.
    K = 1000;
}