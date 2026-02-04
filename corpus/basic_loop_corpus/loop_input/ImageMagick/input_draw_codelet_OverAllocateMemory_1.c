#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is logarithmic in length (base 2), so number of iterations ≈ log2(length) - 8
    // On a modern CPU, each iteration is very fast (a few cycles). To take ~0.01 seconds,
    // assuming ~1e9 iterations per second, we want about 1e7 * 0.01 = 1e7 operations? 
    // But this loop has very few operations per iteration — just a compare and multiply.
    // Let's assume we need around 2^24 (~16M) to get measurable time without being excessive.
    // However, since the loop doubles each time, the number of iterations is small.
    // From 256 to 1<<28 (256MB): iterations = log2(1<<28 / 256) = 28 - 8 = 20 iterations.
    // That’s too few to reach 0.01s unless each iteration were expensive.

    // But the problem says: "suggest 1MB–256MB of input data"
    // So set length to 256MB to satisfy data size requirement.

    length = 256 * 1024 * 1024;  // 256 MB
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}