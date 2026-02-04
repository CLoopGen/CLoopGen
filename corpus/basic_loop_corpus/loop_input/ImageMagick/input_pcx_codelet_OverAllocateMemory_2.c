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
    // Each iteration doubles extent, so number of iterations is about log2(length) - 8 (since starting at 256 = 2^8)
    // On a modern CPU, each iteration is very fast (a few cycles). To get ~0.01s, assuming ~1ns per iteration,
    // we need about 10 million iterations -> log2(length) ~ 8 + log2(10e6) ~ 8 + 23 = 31 -> 2^31 ~ 2GB
    // But 2GB may be too large or cause issues on some systems.
    //
    // However, since the original code does nothing in the loop body, and we are only measuring control flow,
    // we can choose a smaller size that still results in many iterations.
    //
    // Let's aim for around 1 million iterations: log2(length) ≈ 8 + 20 = 28 -> length ≈ 2^28 = 268,435,456 (~256MB)
    // This should be safe and portable.

    length = 268435456;  // 2^28, to ensure about 20 iterations after starting from 256
}

// Initialize extent inside the loop itself, not here — it's controlled by the loop