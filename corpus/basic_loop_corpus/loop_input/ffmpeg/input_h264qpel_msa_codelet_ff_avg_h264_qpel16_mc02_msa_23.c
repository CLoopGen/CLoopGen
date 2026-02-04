#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec on modern CPU

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int32_t loop_cnt;

static uint8_t internal_src[DATA_SIZE];
static uint8_t internal_dst[DATA_SIZE];

void init_vars() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)tv.tv_usec);

    // Initialize data with random values
    for (size_t i = 0; i < DATA_SIZE; i++) {
        internal_src[i] = rand() & 0xFF;
        internal_dst[i] = rand() & 0xFF;
    }

    // Set pointers to middle of arrays to allow safe offsetting in loop
    src = internal_src + (DATA_SIZE / 2);
    dst = internal_dst + (DATA_SIZE / 2);

    // Set stride to a reasonable value (e.g., 64 bytes, typical cache line multiple)
    stride = 64;

    // Ensure that the memory accesses in the loop won't go out of bounds
    // The loop runs 4 times, each time adding 4*stride to src and dst
    // So total offset is 4 * (4 * stride) = 16 * stride
    ptrdiff_t max_offset = 16 * stride;
    if (src - internal_src < max_offset || dst - internal_dst < max_offset ||
        (internal_src + DATA_SIZE - src) < max_offset ||
        (internal_dst + DATA_SIZE - dst) < max_offset) {
        // Adjust pointers to stay within bounds
        src = internal_src + max_offset + (DATA_SIZE - 2 * max_offset) / 2;
        dst = internal_dst + max_offset + (DATA_SIZE - 2 * max_offset) / 2;
    }

    loop_cnt = 4;
}