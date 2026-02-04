#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for a noticeable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length, so we need a large enough length to make it take ~0.01s
    // Each iteration doubles extent, so number of iterations is log2(length) - 8
    // On a modern CPU, each iteration is a few cycles; to get ~0.01s, aim for millions of iterations?
    // But note: this loop is extremely fast — just comparisons and shifts.
    // Even 1e9 iterations would be ~1 second? We want ~0.01s => ~10M iterations.
    // However, the number of iterations is only log2(length/256). To get 10M iterations:
    // log2(length) - 8 = 10^7 => length = 2^(10^7 + 8) — astronomically large, not feasible.

    // Actually, the loop has O(log n) iterations. For length = 2^30 (~1GB), iterations = 30 - 8 = 22.
    // That's only 22 iterations — far too few.

    // So no practical length will make this loop take 0.01 seconds.
    // Therefore, we must assume the loop is part of a larger context or the time comes from elsewhere.
    // But the problem says: "data size that ensures the original loop runs in approximately 0.01 seconds"

    // Since the loop itself is O(log n), we cannot achieve 0.01s with any realistic n.
    // Hence, we suspect that the loop might be intended to control memory access in another loop,
    // but in this code, there are no memory accesses.

    // Given that, we choose a large but reasonable data size for potential use in extended contexts.
    // Let's set length to 128MB worth of pointers or elements, assuming typical usage.

    // However, since the loop does not access memory, we simply define length such that
    // if this were used as an array bound, it would imply a large dataset.

    // Choose length = 1 << 27; // 134,217,728 -> about 128MB if each element is 1 byte
    length = 1 << 27;

    // extent is initialized in the loop, so no need to initialize here beyond what the loop does
    // but we can leave it uninitialized since the loop sets it first
}

// Note: The loop function is defined externally and uses these variables.