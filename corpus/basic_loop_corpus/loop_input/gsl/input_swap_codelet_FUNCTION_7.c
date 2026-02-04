#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t dest_size1;
size_t dest_size2;
size_t i;

void init_vars() {
    // Aim for approximately 0.01 seconds of work
    // Assume modern CPU can do ~1e9 operations/sec -> ~1e7 operations in 0.01s
    // Let's choose total iterations ~1e7, so set dest_size1 * dest_size2 ≈ 10^7

    dest_size1 = 3162;  // approx sqrt(10^7)
    dest_size2 = 3162;

    // This gives about 10 million iterations, which should take ~0.01 seconds
    // depending on actual loop body; since the inner loop is empty,
    // we rely on compiler optimization and loop overhead only.
    // In practice, this size ensures measurable runtime without being excessive.
}