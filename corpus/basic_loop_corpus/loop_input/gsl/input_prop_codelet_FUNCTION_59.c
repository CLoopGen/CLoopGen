#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

void init_vars() {
    // Estimate iteration count for ~0.01s runtime
    // Assume modern CPU can handle roughly 1e9 iterations per second,
    // so 1e7 total iterations should take ~0.01 seconds.
    // Use two-level loop: outer * inner ≈ 1e7
    size1 = 4096;
    size2 = 4096;
}