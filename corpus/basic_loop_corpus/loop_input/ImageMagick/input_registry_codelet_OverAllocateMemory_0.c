#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for a measurable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // doubles extent each iteration. To get around 0.01 seconds, we need enough iterations.
    // On modern CPUs, each iteration is very fast (a few cycles), so we need many iterations.
    // But since this loop only does arithmetic, even millions of iterations are too fast.
    // So instead, we choose a large data size not because the loop needs it,
    // but to match typical benchmarking scenarios.

    // However, note: the loop itself has no memory access — just arithmetic.
    // Therefore, to make it take ~0.01s, we need many iterations.
    // Let's estimate: 2^k >= length, starting from 256 = 2^8.
    // Number of iterations: log2(length) - 8.
    // Suppose we want about 25 iterations (very rough estimate for 0.01s on slow machine),
    // then log2(length) ≈ 33 → length ≈ 2^33 ≈ 8.5GB — too big.

    // Actually, this loop will execute in nanoseconds even for huge length.
    // So we cannot meaningfully delay by data size. Instead, we pick a large but reasonable length
    // such that if this were part of a larger algorithm with memory access, it would be valid.

    // Given no other constraints, pick length = 128MB as a typical medium-large dataset.
    length = 128 * 1024 * 1024;

    // extent is modified in the loop, so no need to initialize beyond what the loop sets
    // but we define it as global so it must be defined
}

// Define the external variables
size_t length = 0;
size_t extent = 0;