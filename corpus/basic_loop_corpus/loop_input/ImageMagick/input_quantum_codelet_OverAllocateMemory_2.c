#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length, so we need a large enough length to take ~0.01s
    // On a modern CPU, each iteration is very fast (a few cycles), so even millions of iterations are sub-millisecond.
    // But since this loop only does multiplications and comparisons, it's extremely fast.
    // To make it take ~0.01 seconds, we need many iterations — but note: doubling from 256 to 2^k takes only about log2(length/256) steps.
    // So to get measurable time, we must make the *body* expensive — but here the body is empty.
    // Therefore, the loop itself will finish in microseconds regardless.
    // To meet the requirement of ~0.01s runtime when compiled and linked, we must assume that the actual work happens elsewhere,
    // or that the compiler may optimize based on data size.

    // However, per instructions, we must set data size between 1MB–256MB unless length is fixed at declaration.
    // Since no array is directly in the loop, but 'length' likely represents a data size, we set it to 64MB as representative.

    length = 64 * 1024 * 1024;  // 64 MB

    // 'extent' is initialized in the loop, so no need to initialize it here beyond ensuring defined behavior
    // But we define it at file scope as required.
}

// Note: The actual loop does nothing except scale extent, so even with large length, execution time is negligible.
// However, this setup ensures that if the loop were part of a larger processing context (e.g., chunking over an array),
    // the length corresponds to a 64MB buffer, which fits within the 1MB–256MB range.