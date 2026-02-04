#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Assuming we want the loop to run for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop runs in O(log(length)) time, specifically log2(length/256) iterations.
    // On a modern CPU, each iteration is very fast (a few cycles).
    // To take ~0.01 seconds, we need enough iterations to accumulate that time.
    // Suppose each iteration takes about 1-2 ns (very fast), then 0.01s = 10,000,000 ns → we'd need millions of iterations.
    // But this loop only does logarithmic steps. So even with length=1EB, it's only ~30 iterations.
    // Therefore, the original loop is too cheap to measure in 0.01s.

    // However, the problem says: "suggest 1MB–256MB of input data"
    // And the variable names 'length' and 'extent' suggest buffer sizes.

    // Since the loop itself cannot be made to run longer without changing its logic,
    // we interpret the requirement as setting up data so that if this loop were part of a larger
    // computation over a buffer of size `length`, then that buffer should be sized to meet
    // performance assumptions.

    // We'll set length to 64 MB (67,108,864 bytes), which falls in the suggested range.
    length = 64 * 1024 * 1024;  // 64 MB

    // extent is initialized inside the loop to 256, so no need to initialize it here
    // but we define it as global so it persists; init_vars doesn't need to touch extent
}

// Define the loop function externally, but we don't redefine it here.
// This file only defines the external variables and init_vars.