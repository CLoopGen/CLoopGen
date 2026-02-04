#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for a noticeable duration
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This loop doubles 'extent' each iteration, so number of iterations is log2(length/256)
    // To make it run around 0.01 seconds, we choose length such that iterations are in thousands
    // On modern CPUs, each iteration is very fast (a few cycles), so we need many iterations.
    // Let's set length to 2^30 (~1GB) so that iterations = log2(2^30 / 2^8) = 22 iterations.
    // But that's too few. We need more work.

    // However, note: the loop as given has no body — it's just incrementing extent.
    // So even millions of iterations take microseconds.
    // To make it take ~0.01s, we need to simulate workload? But we can't change the loop.

    // Actually, since the loop is empty and only does logarithmic steps, even with huge length,
    // the number of iterations is small. For example:
    // If length = 2^60, iterations = log2(2^60 / 256) = 60 - 8 = 52 → still negligible time.

    // Therefore, any reasonable length will make this loop finish in nanoseconds.
    // But requirement says: "data size that ensures the original loop runs in approx 0.01 seconds"
    // Since the loop control itself cannot be slowed meaningfully, perhaps the intention is
    // that the surrounding context uses these variables for memory access?

    // However, the loop code provided has no memory accesses.

    // Given that, we choose a large but safe value for length to reflect typical usage.
    // Let's assume the system is 64-bit and we want to use significant but not excessive memory.
    // We'll set length to 128MB worth of elements if used as array index, but here it's just a bound.

    // Since the only constraint is that extent grows from 256 to < length by doubling,
    // and we must avoid overflow, we pick length = 1 << 30 (about 1 GB) which gives about 22 iterations.
    length = 1U << 30;  // 2^30
    // extent is modified in the loop, so no need to initialize here for correctness,
    // but we initialize it in the loop to 256 anyway.
}

// Note: The loop function modifies 'extent', so its initial value doesn't matter,
// but the loop starts with extent=256 unconditionally.