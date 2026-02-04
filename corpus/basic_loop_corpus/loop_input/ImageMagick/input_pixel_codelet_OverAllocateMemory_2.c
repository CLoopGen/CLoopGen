#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in base 2 from 256 to length -> iterations = log2(length) - 8
    // On a modern CPU, each iteration is very fast (a few cycles). To take ~0.01s, assume ~10^7 operations per second per core
    // So we want roughly several million iterations? Actually no — this loop is extremely cheap.
    // Benchmarking shows that ~1e9 iterations take about 1-2 seconds on modern CPUs for such a simple loop.
    // Therefore, for 0.01s, we need about 10 million iterations: log2(length) - 8 ≈ 10^7 → not feasible (length would be astronomical).

    // Actually, reevaluate: the number of iterations is only log2(length / 256). For length = 1GB (2^30), iterations = 30 - 8 = 22.
    // So even with huge arrays, the loop runs only tens of iterations.

    // Therefore, the cost is negligible. We must interpret "runs in approximately 0.01 seconds" as referring to the data size,
    // not the loop execution time. Likely, the intent is to have large data so that when combined with other memory-accessing code,
    // timing is meaningful. But here, the loop doesn't access memory.

    // However, since the problem says "suggest 1MB–256MB", and to ensure memory accesses don't go out of bounds,
    // we can set length to 128MB to be within suggested range.

    // But note: the loop itself does not access any array — it just manipulates extent.
    // Still, to satisfy potential future memory accesses (if this loop were part of a larger pattern),
    // we choose a large enough length.

    // Let's set length to 134217728 (128 MiB) to fit in suggested range.
    length = 134217728;  // 128 * 2^20

    // extent is modified in the loop, so no initialization needed beyond what the loop sets
    // but we define it as global, so it will be zero-initialized if not set — but loop sets it to 256 first
}

// Note: No main() included as per instructions