#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Determine K such that the nested loop runs approximately 0.01 seconds
    // The loop has O(K^2) iterations, so we choose K accordingly.
    // On a typical modern CPU, we assume ~1e9 operations per second.
    // For 0.01 seconds, we target roughly 1e7 operations.
    // Solving K*(K-1)/2 ≈ 1e7 → K ≈ sqrt(2e7) ≈ 4472
    K = 4472;
}