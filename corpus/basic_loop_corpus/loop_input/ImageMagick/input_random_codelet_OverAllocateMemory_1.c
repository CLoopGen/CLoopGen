#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in base 2 from 256 to length -> number of iterations ≈ log2(length) - 8
    // On a modern CPU, each iteration is very fast (a few cycles). To reach ~0.01 seconds (10ms),
    // we need enough iterations to accumulate that time. However, since the loop body is empty,
    // it may be optimized away unless we prevent such optimization.
    //
    // But since we are only initializing variables and not modifying the loop,
    // we choose a large enough length so that the loop has many iterations,
    // but the actual runtime will still be negligible due to simplicity.
    //
    // However, to simulate realistic timing and ensure compiler does not optimize everything,
    // we pick a large data size. But note: no arrays are accessed in this loop.
    // So we just need to make sure the scalar operations take measurable time.
    //
    // Let's assume we want around 1e7 iterations to make the loop non-trivial.
    // Since extent doubles each time: 256, 512, ..., until >= length
    // Number of iterations: floor(log2(length)) - 8
    // Solve: log2(length) - 8 ≈ 1e7  => log2(length) ≈ 1e7+8 => length ≈ 2^(1e7) which is astronomical.
    //
    // That can't be right. Actually, even 30 iterations would take negligible time.
    // Therefore, the original loop with an empty body will always run in nanoseconds.
    //
    // But requirement says: "ensure the original loop runs in approximately 0.01 seconds"
    // So we must prevent optimization. However, we cannot change the loop.
    //
    // Alternative interpretation: perhaps the data size refers to memory footprint
    // of the program, not the loop execution time? But the instruction says:
    // "Uses a data size that ensures the original loop runs in approximately 0.01 seconds"
    //
    // Given the confusion, and because the loop has no body, we instead interpret it as:
    // use a data size in the recommended range (1MB–256MB) for any arrays — but there are none.
    //
    // So we focus on making the loop have many iterations without causing overflow.
    // We can't make it too large or extent will overflow.
    //
    // Maximum extent before overflow (assuming 64-bit): near 2^63
    // Starting at 256 = 2^8, so max iterations: about 63 - 8 = 55
    // Even if we could repeat the loop many times, we can't control that here.
    //
    // Therefore, we set length to a large value within safe bounds to allow maximum iterations.
    // Let's set length to 2^60, which is within size_t on 64-bit systems.

    length = ((size_t)1) << 60;  // Very large so the loop runs many iterations (about 52)

    // Initialize extent to avoid undefined behavior on first read if used elsewhere
    extent = 256; // though the loop sets it first
}