#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t k1;
size_t q = 1024;
size_t m = 512;
size_t product_1 = 2048;

void init_vars() {
    // Ensure that the loop runs with data size leading to approximately 0.01 seconds of execution
    // Using heuristic values for q, m, product_1 to achieve moderate computation load
    // The expressions in the loop involve indices up to (2 * k1 * q + q - 1) and (k1 * q + q - 1 + m)
    // We choose values so that memory accesses would be safe if arrays were based on max required index

    // Recompute worst-case index to ensure safety margin
    // Maximum value of from0: 2 * (product_1 - 1) * q + q - 1 = 2 * 2047 * 1024 + 1023 ≈ 4.2e6
    // Maximum value of to1: (product_1 - 1) * q + q - 1 + m = 2047*1024 + 1023 + 512 ≈ 2.1e6
    // These suggest array sizes ~4MB if byte-accessed; we stay within reasonable bounds

    // Current values of q=1024, m=512, product_1=2048 yield about O(2e6) iterations and indirect operations
    // This should execute in roughly tens of milliseconds on modern CPUs without excessive memory use
}