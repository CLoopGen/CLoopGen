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
    // On a modern CPU, each iteration is very fast (a few cycles). To take ~0.01s at ~3GHz, we need roughly 30M cycles.
    // Assuming ~10 cycles per iteration, that's about 3M iterations — but this loop only does O(log n) steps.
    // So instead, we must interpret "runs in approximately 0.01 seconds" as being part of a larger context.
    // However, this loop itself has O(log n) iterations and will execute extremely quickly unless length is enormous.

    // But note: this loop does nothing except increment extent. It's likely used as a timing harness or warm-up.
    // To make this loop take measurable time (~0.01s), we need many iterations.
    // Each iteration is a compare and a multiply — very cheap (<10 cycles).
    // For 0.01s @ 3GHz → 30e6 cycles → if each iteration takes 10 cycles → 3e6 iterations needed.

    // However, this loop doubles `extent` each time: number of iterations = floor(log2(length)) - 8
    // So: log2(length) ≈ 3e6 + 8 → length ≈ 2^(3e6) — which is astronomically large and not feasible.

    // Therefore, the intended interpretation must be that this loop is *not* meant to run for 0.01s by itself,
    // but rather it's a setup loop used before another computation (like finding a power-of-2 buffer size),
    // and the data size should be chosen so that subsequent processing would take ~0.01s.

    // Given the ambiguity, we choose a moderate data size between 1MB and 256MB as suggested.
    // Let's pick 64 MB of dummy data to represent a reasonable workload.

    // We don't have arrays in this code, but `length` likely represents a data size.
    // Set length to 67108864 (64 * 2^20) bytes worth if unit is byte, but here length is just a size_t counter.

    // Since no actual array is accessed in the loop, we just need to set `length` large enough
    // so that the loop does a reasonable number of iterations — say around 25 iterations:
    // start at 256 = 2^8, then 2^9, ..., up to 2^32 → 24 iterations → within reason.

    // But again, 24 iterations is nanoseconds. So perhaps the loop is meant to be representative
    // when length is large. We'll set length to a value that implies a large dataset,
    // say 64 MiB, assuming each element is 1 byte → length = 67108864.

    length = 67108864;  // 64 * 1024 * 1024 = 64 MiB

    // extent is initialized inside the loop, so no need to initialize here
    // but we can leave it uninitialized since loop sets it first
}

// Note: The loop function is defined externally and will use these variables.