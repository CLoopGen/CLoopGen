#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t length;
size_t extent;

void init_vars() {
    // Set length to a value that ensures the loop runs for approximately 0.01 seconds
    // The loop: for (extent = 256; extent < length; extent *= 2) does O(log(length)) iterations
    // On a modern CPU, each iteration is very fast. To achieve ~0.01s, we need enough iterations.
    // log2(2^24) = 24 iterations starting from 256 (2^8), so length around 16MB gives about 16 iterations.
    // But since operations are minimal, we increase data size to ensure measurable time.
    // Let's set length to 2^30 (~1GB) to ensure sufficient iterations and timing headroom.

    length = (1ULL << 30);  // 1 GB equivalent in indexing scale
}

void loop();  // Forward declaration

__attribute__((constructor))
static void auto_init() {
    init_vars();
}