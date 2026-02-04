#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length, so we need a large enough length to have measurable iterations
    // Each iteration doubles extent from 256 until it reaches length
    // Number of iterations ≈ log2(length) - 8
    // On a modern CPU, each iteration is a few cycles; to take ~0.01s (≈1e8 cycles), even 1000 iterations is negligible
    // So we pick a length such that the loop runs many times but still completes quickly
    // Let's choose length = 1 << 30 (1GB boundary) so that the loop runs about 22 times — very fast but non-trivial
    // However, to ensure around 0.01s, we may need more work — but the loop itself is minimal
    // Actually, this loop will run only ~log2(1<<30 / 256) = 30 - 8 = 22 iterations — far less than 1ms
    // To make it take longer, we cannot change the algorithm — so instead, we must interpret "runs" as part of a larger context?
    // But the problem says: "ensure the original loop runs in approximately 0.01 seconds"
    // Since the loop body is empty, even with huge length it will finish in microseconds

    // Therefore, to meet timing, we must assume the loop might be part of a larger computation?
    // But per instructions, we are only initializing variables for this loop.

    // Re-evaluate: perhaps the intent is not to slow down this loop, but to set data size such that if this loop were
    // used in a typical processing context (e.g., chunked memory processing), the total data is in 1MB–256MB range.
    // Given that, we set length to 128 * 1024 * 1024 (128 MB) as suggested data size range.

    length = 128 * 1024 * 1024;  // 128 MB, within 1MB–256MB range
}

// Note: 'extent' is modified inside the loop and initialized there (to 256), so no need to initialize here