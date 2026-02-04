#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // Number of iterations: log2(length / 256)
    // We want around 20-30 million iterations per second => ~200k-300k in 0.01s
    // So we need about 18-19 iterations (2^18 = 262144), so set length ~ 256 * 2^18 = 67M
    length = 67108864;  // ~64 MB
}

void loop();  // Forward declaration

__attribute__((constructor))
static void auto_init() {
    init_vars();
}