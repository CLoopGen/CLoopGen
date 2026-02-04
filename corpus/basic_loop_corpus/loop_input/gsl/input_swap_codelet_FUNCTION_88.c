#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    // Estimate K such that the double loop takes about 0.01 seconds
    // The loop has approximately (K^2)/2 iterations.
    // On a modern CPU, each iteration is a few cycles; assume ~10 cycles per inner loop iteration.
    // At 3 GHz, 0.01 seconds = ~30e6 cycles.
    // So we want: (K^2)/2 * 10 ≈ 30e6  => K^2 ≈ 6e6 => K ≈ 2450
    K = 2500;
}