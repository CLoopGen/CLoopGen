#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 8192;
size_t N = 8192;
size_t tda_a = 8192;
size_t tda_b = 8192;
size_t i;
size_t j;

void init_vars() {
    // No additional initialization needed for scalar variables
    // Sizes are chosen to create ~1GB of effective access (2 * M * N * sizeof(size_t) equivalent)
    // This ensures the loop runs around 0.01 seconds on modern hardware
}