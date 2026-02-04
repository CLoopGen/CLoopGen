#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs for a noticeable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop doubles 'extent' each iteration, so number of iterations is log2(length) - 8
    // To make it run about 0.01 seconds, we need many iterations — but the loop itself is very fast (logarithmic).
    // So instead, we interpret that we should set 'length' large enough that if this were part of a larger data processing,
    // the data size would dominate. Since no array is visible, we assume 'length' refers to a data size.

    // Let's assume typical modern CPU does ~1e9 iterations/sec -> 0.01 sec = 1e7 iterations.
    // But our loop only does O(log n) iterations. To get ~1e7 iterations in the doubling loop? Impossible — log2(n) grows slowly.
    // Even with length = 2^1e7, which is astronomical, won't help.

    // Therefore, likely intention is that this loop is a setup for divide-and-conquer over a data region.
    // We choose length such that the problem size is about 64MB to 128MB to fit "typical" data size.

    // However, note: the loop doesn't access memory — it just runs O(log n) times.
    // But since no arrays are mentioned, and only 'length' and 'extent', we must define them meaningfully.

    // Given ambiguity, pick length large enough that if used as array size later, would take time.
    // Choose length = 67108864 (i.e., 64 * 2^20) ≈ 64 million → log2(64M)=26 → loop runs ~18 iterations (from 256=2^8 to 2^26)
    // That’s realistic and safe.

    length = 67108864;  // ~64 million
    extent = 256;       // will be set by loop, but initialize here too via init_vars?
    // But note: loop sets extent=256 in initialization, so no need to pre-initialize beyond what's needed for correctness.
}

// Note: No main() included as per instructions.