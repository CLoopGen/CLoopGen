#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K to achieve approximately 0.01 seconds of execution
    // The loop has O(K^2) iterations: sum_{i=0}^{K-1} i = K*(K-1)/2 ≈ K^2/2
    // On a modern CPU, each iteration is a few cycles; assume ~10 cycles per inner loop iteration
    // 0.01 seconds at 3 GHz = ~30 million cycles
    // So we want K^2/2 * 10 ≈ 30e6  => K^2 ≈ 6e6 => K ≈ 2450
    K = 2500;
}