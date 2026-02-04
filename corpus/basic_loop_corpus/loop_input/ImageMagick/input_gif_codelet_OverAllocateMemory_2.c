#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop runs in logarithmic time (base 2) relative to length
    // Number of iterations: log2(length) - 8 (since starting at 256 = 2^8)

    // On a modern CPU, each iteration is very fast (a few cycles).
    // To achieve ~0.01 seconds, we need enough iterations so that even though
    // each is fast, the total count gives measurable time.

    // Assume ~10ns per iteration -> 1e7 iterations needed for 0.1s, but we want 0.01s -> ~1e6 iterations.
    // But this loop only does O(log n) iterations. So to get many iterations, we need huge length?
    // Actually: iterations = floor(log2(length)) - 8
    // For length = 2^30 (~1GB), iterations = 30 - 8 = 22
    // That's too few.

    // Therefore, the original loop is extremely fast — only about 20-30 iterations even for GBs of data.
    // To make it take ~0.01s, we cannot rely on large data alone — but the problem says:
    // "suggest 1MB–256MB of input data unless the length is specified"

    // However, note: the loop doesn't access memory — it just does integer operations.
    // So runtime is negligible regardless of data size.

    // But the requirement says: "ensure the original loop runs in approximately 0.01 seconds"
    // Since the loop is so short, we must reinterpret: perhaps the intention is to set up data
    // such that if this were part of a larger computation (like doubling buffer sizes),
    // then the final length would be meaningful.

    // Given no further context, and since the loop itself will always run in nanoseconds,
    // we choose a typical large size for data processing: 64 MB

    const size_t data_size = 64 * 1024 * 1024; // 64 MB
    length = data_size;

    // Initialize extent inside init_vars, though it's overwritten in loop anyway
    // We just ensure it's defined
    extent = 0;
}