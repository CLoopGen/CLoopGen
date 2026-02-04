#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of work
    // Assuming the inner loop performs minimal work, we need to estimate data size.
    // Let's assume a modern CPU does ~1e9 iterations per second.
    // For 0.01 seconds, we aim for about 1e7 total iterations (i * j).
    // We choose dimensions such that dest_size1 * dest_size2 ≈ 10^7.

    dest_size1 = 3200;
    dest_size2 = 3200;
}