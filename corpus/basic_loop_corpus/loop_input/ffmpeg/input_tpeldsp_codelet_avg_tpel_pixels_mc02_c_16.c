#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static uint8_t memory_pool_src[TOTAL_BYTES];
static uint8_t memory_pool_dst[TOTAL_BYTES];

void init_vars() {
    width = 4096;
    stride = width + 16;
    height = (TOTAL_BYTES) / stride;
    if (height * stride > TOTAL_BYTES) {
        height = TOTAL_BYTES / stride;
    }
    src = memory_pool_src;
    dst = memory_pool_dst;

    for (int idx = 0; idx < height * stride; ++idx) {
        memory_pool_src[idx] = rand() & 0xFF;
        memory_pool_dst[idx] = rand() & 0xFF;
    }

    i = 0;
    j = 0;
}