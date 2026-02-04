#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for ~0.01 sec runtime on modern CPU

uint8_t *dst;
uint8_t *src;
ptrdiff_t w;
long i;

static uint8_t src_data[DATA_SIZE] __attribute__((aligned(64)));
static uint8_t dst_data[DATA_SIZE] __attribute__((aligned(64)));

void init_vars() {
    w = DATA_SIZE - (ptrdiff_t)sizeof(long); // Ensure no out-of-bounds access
    src = src_data;
    dst = dst_data;

    // Initialize src and dst with non-zero predictable data
    for (size_t j = 0; j < DATA_SIZE; ++j) {
        src_data[j] = (uint8_t)(j & 0xFF);
        dst_data[j] = (uint8_t)((j ^ 0x5A) & 0xFF);
    }
}