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
    // Each iteration doubles extent, so number of iterations is log2(length) - 8 (since starting at 256 = 2^8)
    // On a modern CPU, each iteration is very fast (a few cycles). To achieve ~0.01 seconds,
    // assuming ~10 ns per iteration (conservative), we need about 1e6 / 10 = 100,000 iterations.
    // But since it's just a loop with no body, compiler may optimize it away unless we prevent that.

    // To force observable execution time, set length such that the loop runs many times.
    // However, note that the loop has no body — it's just incrementing extent.
    // The actual work is minimal. We need to choose length so that the number of iterations
    // leads to measurable time. Let's target around 2^20 iterations? That would be too long.
    // Actually, doubling from 256: iterations = log2(length) - 8.
    // So if we want 30 iterations -> length ~ 2^(38) which is huge.

    // Wait: this loop does not iterate 30 times — it does one check per power of two.
    // For length = 1GB (2^30), iterations = 30 - 8 = 22. That's only 22 iterations — too fast.

    // Therefore, to make it take 0.01 seconds, we must have many more iterations.
    // But this loop is O(log n), so even with huge length, iterations are small.
    // Example: length = 2^60 -> iterations = 60 - 8 = 52. Still less than 100.

    // So regardless of data size, this loop will always execute in negligible time (< 1 microsecond).
    // Thus, we cannot meaningfully scale input size to meet 0.01 seconds.

    // Instead, we interpret the requirement as ensuring the program is well-defined and safe.
    // We'll set length to a moderate size, say 1MB, though it won't affect performance meaningfully.

    // Since there are no array accesses or memory operations in the loop,
    // we don't need large arrays. Just define the scalars.

    length = 1024 * 1024; // 1MB as nominal data size reference
    extent = 256; // but this will be overwritten by loop, so doesn't matter
}

// Note: The loop function uses only scalar variables and performs no memory access.
// Therefore, no arrays or pointers are needed beyond what's declared.