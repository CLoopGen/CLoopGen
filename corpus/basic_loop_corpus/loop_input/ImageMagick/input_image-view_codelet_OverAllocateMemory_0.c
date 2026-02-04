#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop runs in logarithmic time (log2(length / 256))
    // To make it take ~0.01s, we need enough iterations. Each iteration is very fast.
    // On a modern CPU, aim for several thousand iterations to be measurable.
    // Let's target about 10,000 iterations: 256 * 2^10000 would be astronomical.
    // But note: this loop only does multiplication and comparison — extremely cheap.
    // Instead of huge iteration counts, realize that even 30 iterations (length = 2^30) takes negligible time.
    // So instead, we must scale *data size* to consume memory bandwidth or cache effects?
    // However, the loop has no data — it's pure control flow.

    // Since the loop has no memory operations, its runtime is dominated by a few integer ops.
    // Even millions of iterations are under microseconds. We cannot achieve 0.01s with just this loop.
    // Therefore, assume the intended use involves data arrays accessed elsewhere, so set length
    // to a moderate size like 16MB elements if it were an array index.

    // Given no array is visible here, but `length` bounds the loop, choose `length` such that
    // the number of iterations is reasonable and could relate to a real problem size.
    // For example, 2^28 = 268,435,456 — starting from 256, doubling each time:
    // Number of iterations: log2(268435456 / 256) = log2(1048576) = 20 → very fast.

    // But requirement says: "suggest 1MB–256MB of input data"
    // So we interpret `length` as number of bytes in a dataset.

    // Set length to 64MB to fit within suggested range and allow sufficient iterations
    // Iterations: from 256 to 64MB -> 2^26 = 67,108,864
    // Iterations: log2(67108864 / 256) = log2(262144) = 18 iterations — still small

    // There's no way to make this loop take 0.01s unless we misinterpret.
    // However, perhaps the loop is meant to be part of a larger algorithm.
    // We follow the data size guidance: use 64MB as base.

    length = 64 * 1024 * 1024;  // 64 MB
}

// Explicitly define all extern variables
size_t length = 64 * 1024 * 1024;
size_t extent = 0;