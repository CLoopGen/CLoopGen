#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int16_t *dst;
int16_t *b0;
int16_t *b1;
int16_t *b2;
int16_t *b3;
int16_t *b4;
int16_t *b5;
int16_t *b6;
int16_t *b7;

void init_vars() {
    // Aim for approximately 1MB - 256MB of total data; let's target ~64MB of input data
    // Each array has width elements of int16_t (2 bytes), and we have 9 arrays (dst + b0..b7)
    // Total memory = 9 * width * 2 = 18 * width bytes
    // For ~64MB: width ≈ 64*1024*1024 / 18 ≈ 3.7 million
    width = 1 << 21;  // 2^21 = 2,097,152 elements (~37MB total)

    // Allocate arrays
    dst = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b3 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b4 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b5 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b6 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b7 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    // Initialize arrays with pseudo-random data for realistic computation
    srand(time(NULL));
    for (int idx = 0; idx < width; idx++) {
        dst[idx] = rand() % 65536 - 32768;
        b0[idx] = rand() % 65536 - 32768;
        b1[idx] = rand() % 65536 - 32768;
        b2[idx] = rand() % 65536 - 32768;
        b3[idx] = rand() % 65536 - 32768;
        b4[idx] = rand() % 65536 - 32768;
        b5[idx] = rand() % 65536 - 32768;
        b6[idx] = rand() % 65536 - 32768;
        b7[idx] = rand() % 65536 - 32768;
    }

    // Ensure i is initialized to a safe value (will be overwritten in loop anyway)
    i = 0;
}