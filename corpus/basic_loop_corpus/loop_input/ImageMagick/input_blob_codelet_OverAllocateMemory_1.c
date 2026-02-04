#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2) runs in O(log(length)) steps
    // Each iteration doubles 'extent'. To get around 10-20 iterations, set length to about 1MB to 256MB scale

    // Let's target ~18 iterations: 256 * 2^18 = 256 * 262144 = 67,108,864 (~67M)
    // This should take roughly 0.01 seconds if each iteration were expensive, but since it's just arithmetic,
    // we must ensure data size doesn't dominate. However, no data is accessed yet.

    // But the problem says "data size that ensures the original loop runs in approximately 0.01 seconds"
    // Since the loop does only logarithmic work, even with huge length it's fast.
    // So we interpret as: choose length such that if this were part of a larger data processing context,
    // the effective data size is in the 1MB–256MB range.

    // We'll set length to 67,108,864 (64MB worth of elements if sizeof(element)=1)
    length = 67108864;  // ~64 million
}

void loop();  // Forward declaration

// Call this before calling loop() to initialize required variables
void initialize() {
    init_vars();
}