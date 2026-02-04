#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the loop runs in approximately 0.01 seconds
    // The loop has O(K^2) iterations: sum_{i=0}^{K-1} i = K*(K-1)/2 ≈ K^2/2
    // On a modern CPU, each iteration is a few cycles; assume ~10 cycles per inner loop iteration
    // At 3 GHz, 0.01 seconds = 30e6 cycles available
    // So we want: K^2/2 * 10 ≈ 30e6  => K^2 ≈ 6e6 => K ≈ 2450
    K = 2500;
}