#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs for a noticeable duration.
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is a logarithmic loop (base 2), so number of iterations is about log2(length) - 8.
    // To make it run ~0.01 seconds, we need enough iterations — say thousands.
    // But since each iteration is very cheap (just a multiply and compare),
    // even with large length, total time is tiny. So we pick a large enough length
    // such that the loop runs many times, but still safe.

    // However, note: the loop doesn't do work per se — just increments extent exponentially.
    // So even if length is huge, the number of iterations is only logarithmic.
    // Example: length = 1 << 30 (~1GB), then iterations = 30 - 8 = 22.
    // That's too few to take 0.01s unless each iteration were heavy.

    // Since the loop body is empty, the entire loop compiles down to almost nothing.
    // To simulate realistic timing context, we must assume that in the real program,
    // there might be more code — but here, we are only initializing variables.

    // Therefore, we choose length such that memory bounds would be reasonable
    // if arrays were involved. We pick 128MB of data as a typical medium-large size.

    // But no arrays are used in this loop. Only scalar variables.
    // So we just need to set length to a value that makes the loop non-trivial.

    // Let's aim for about 20-25 iterations to give measurable behavior under profiling.
    // Start at 256, double until >= length.
    // Number of iterations: floor(log2(length)) - 8 + 1? Actually: while (extent < length) -> runs while extent < length

    // To get ~20 iterations: 256 * 2^k >= length => k ≈ log2(length) - 8
    // So set length = 1 << 30 (about 1 billion) to get ~22 iterations.

    length = 1ULL << 30;  // 1 GB equivalent, ensures about 22 iterations
    extent = 256;          // will be overwritten by loop, but initialize anyway
}