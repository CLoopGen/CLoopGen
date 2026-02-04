#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
uint8_t *cm;
int w;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of input data for sufficient runtime

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    // Allocate buffers
    dst_buffer = (uint8_t *)calloc(DATA_SIZE, sizeof(uint8_t));
    src_buffer = (uint8_t *)calloc(DATA_SIZE + 17, sizeof(uint8_t)); // Need 17 rows due to src[16 * srcStride]
    cm_buffer = (uint8_t *)calloc(512, sizeof(uint8_t)); // cm indexed via complex expression, give ample space

    // Initialize global pointers
    dst = dst_buffer;
    src = src_buffer;
    cm = cm_buffer;

    // Stride values: use 1 for simplicity, so incrementing pointer moves by one byte
    dstStride = 1;
    srcStride = 1;

    // Set width: number of iterations to get desired computation load
    w = DATA_SIZE / 16; // Adjust so we access reasonable portion of buffer

    // Ensure we don't go out of bounds: limit w such that src + 16*srcStride + w <= src_buffer + allocated size
    int max_w = (DATA_SIZE + 17 - 17) / 1; // Since srcStride=1 and we need up to src[16] in each iteration
    if (w > max_w) w = max_w;

    // Initialize src with non-zero test pattern
    for (int j = 0; j < DATA_SIZE + 17; j++) {
        src_buffer[j] = (uint8_t)(j % 251);
    }

    // Initialize cm with identity-like mapping modulated by index
    for (int j = 0; j < 512; j++) {
        cm_buffer[j] = (uint8_t)((j * 17 + 13) % 256);
    }

    // Initialize i to zero (loop counter)
    i = 0;
}