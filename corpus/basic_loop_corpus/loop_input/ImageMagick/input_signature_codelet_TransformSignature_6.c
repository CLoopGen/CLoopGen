#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t i;
unsigned char *p;
unsigned int shift;
unsigned int T;
unsigned int W[64];

static unsigned char data_buffer[256 * 1024 * 1024]; // 256 MB buffer

void init_vars() {
    // Initialize shift to a valid bit shift value (0 to 31)
    shift = 16;

    // Initialize p to point into the data buffer
    p = data_buffer;

    // Ensure the buffer is large enough for the loop: 16 iterations, each reading 4 bytes via unsigned int
    // But pointer advances by 8 bytes per iteration -> total 16 * 8 = 128 bytes needed
    // We have 256MB, so plenty of space.

    // Seed and fill buffer with pseudo-random data for realistic access patterns
    uint64_t seed = 123456789ULL;
    size_t buf_size = 128;
    for (size_t j = 0; j < buf_size / sizeof(uint64_t); ++j) {
        ((uint64_t*)data_buffer)[j] = seed;
        seed *= 1103515245ULL + 12345;
    }

    // Initialize W array to zero to avoid undefined behavior
    memset(W, 0, sizeof(W));

    // Initialize T to zero
    T = 0;
}