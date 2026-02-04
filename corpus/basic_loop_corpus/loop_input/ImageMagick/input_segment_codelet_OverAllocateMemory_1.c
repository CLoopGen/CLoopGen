#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs for a measurable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // runs O(log(length)) iterations. To achieve ~0.01s, we need sufficient iterations.
    // On modern CPUs, each iteration is very fast. Setting length to 2^30 (~1GB) ensures
    // about 24 iterations (from 256 to 2^30), which is enough to be measurable.

    length = (1ULL << 30);  // ~1GB worth of logical data size to ensure warm-up and measurable time
}

// Ensure that when loop() is called, all variables are initialized
__attribute__((constructor))
static void initialize() {
    init_vars();
}