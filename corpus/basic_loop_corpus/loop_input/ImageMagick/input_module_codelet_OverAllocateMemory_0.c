#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length (base 2), so number of iterations ≈ log2(length) - 8

    // On a modern CPU, each iteration is very fast. To take ~0.01 seconds, we need several million iterations.
    // But note: this loop only does extent *= 2, so it's extremely cheap.
    // Empirical tuning: with length = 1 << 30 (~1GB), we get about 22 iterations — too few.
    // Actually, the number of iterations is floor(log2(length)) - 8.

    // To achieve ~0.01s, assuming each iteration takes ~1ns (very fast), we need ~10,000,000 iterations.
    // But this loop will never run that many times because extent doubles each time.
    // Maximum iterations: if length is 2^64, iterations = 64 - 8 = 56.

    // Therefore, the loop is inherently bounded to at most ~60 iterations on 64-bit systems.
    // So no matter how large length is, the loop runs in negligible time (<< 1ms).

    // Thus, we choose a large but safe length to simulate a big data context.
    // Let's set length to 256MB worth of elements? But the loop doesn't iterate over data per se.

    // However, the problem says: "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"
    // Since the loop is O(log n), we cannot make it run longer by increasing length meaningfully.

    // Therefore, we must reinterpret: perhaps the loop is part of a larger algorithm that processes data?
    // But as given, it's just a logarithmic counter.

    // Best interpretation: ensure that the values are initialized such that the loop is meaningful,
    // and if there were array accesses using 'extent', we want to avoid out-of-bounds.

    // Assume that 'length' corresponds to an array size, and we want to avoid accessing beyond it.
    // We'll set length to 256 * 1024 * 1024 (256 MB) as suggested by the typical range.

    length = 256 * 1024 * 1024;
    // extent is used in the loop and initialized inside, so no need to initialize here beyond what the loop does.
}

// Note: 'extent' is modified in the loop, so we don't initialize it here.