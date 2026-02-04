#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length, so we need a large enough length to create measurable delay

    // On a typical modern CPU, multiplying by 2 and comparing takes a few cycles.
    // To get ~0.01s, assuming ~1e9 operations per second, we want ~1e7 operations.
    // But the loop runs only log2(length/256) iterations.

    // Solve: log2(N/256) ≈ 25 => N ≈ 2^25 * 256 = 2^33 which is too large.

    // Actually, the number of iterations is small even for large arrays.
    // For example, if length = 2^30 (1GB), then:
    //   extent starts at 256 = 2^8, doubles each time: 2^8, 2^9, ..., up to 2^30 -> 22 iterations.
    // So the loop is extremely fast — just ~20 iterations.

    // Therefore, to make it take ~0.01s, we need to increase the work per iteration or recognize
    // that this loop alone cannot consume significant time unless repeated.

    // However, the problem says "ensure the original loop runs in approximately 0.01 seconds".
    // Since the loop has no inner work, even billions of elements yield only ~30 iterations.

    // Thus, we must assume that either:
    //   - The loop body was omitted but implied to do O(extent) work
    //   - Or we are to scale length so that if this were part of a larger algorithm, data size fits

    // Given ambiguity, choose length such that it represents a moderate-sized dataset,
    // say 64MB to 256MB, which is common for performance testing.

    length = 64 * 1024 * 1024;  // 64 MB

    // extent is initialized in the loop, so no need to set here
}

// Note: The loop function itself is defined externally and will use these variables.