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
    // Each iteration does very little, so we need to ensure many iterations.
    // On a modern CPU, aim for ~1e7 to 1e8 operations for ~0.01s.
    // But this loop only does O(log n) iterations. To get enough iterations, set length very large.

    // Number of iterations: log2(length / 256)
    // We want around 25-30 iterations to take ~0.01s (each iteration is a few cycles, but let's overestimate overhead)

    // Let's set length to 2^30 (~1GB index space) to get about 30 - 8 = 22 iterations
    length = (1ULL << 30);  // Approximately 1 billion elements if it were an array

    // Initialize extent inside the loop itself, so no need to initialize here beyond what's required for correctness
    // The loop starts at 256 and doubles until reaching length
}

// Ensure the variables are defined and will be linked properly with the loop function