#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to ensure the loop runs approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2)
    // This is a logarithmic loop (base 2), so number of iterations ≈ log2(length) - 8
    // To simulate ~0.01s on modern CPU, aim for around 20-25 iterations (each iteration is very fast)
    // Let's choose length such that it results in about 24 iterations: 2^24 ≈ 16.7M
    length = 1 << 24;  // 16,777,216
}

void loop();  // forward declaration

// Ensure linkage with external loop function
__attribute__((constructor))
static void auto_init() {
    init_vars();
}