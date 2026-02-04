#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the double loop runs approximately 0.01 seconds
    // The loop has O(K^2) iterations. On a modern CPU, each iteration is a few cycles.
    // Assume ~1e9 iterations per second -> 1e7 iterations in 0.01s.
    // Solve K*(K-1)/2 ≈ 1e7 -> K ≈ sqrt(2e7) ≈ 4472
    K = 4500;
}