#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define TOTAL_DATA_SIZE (128 * 1024 * 1024) // Aim for ~128MB of data
#define BLOCK_HEIGHT 8
#define BLOCK_WIDTH 8

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

void init_vars() {
    // Choose image dimensions to process about 128MB via 8x8 blocks
    int total_pixels = TOTAL_DATA_SIZE;
    int width = 2048; // Heuristic: choose width as power of 2
    height = ((total_pixels + width - 1) / width); // Adjust height accordingly
    // Round height up to multiple of 8 for full block processing
    height = ((height + BLOCK_HEIGHT - 1) / BLOCK_HEIGHT) * BLOCK_HEIGHT;

    src_stride = width;
    dst_stride = width;

    // Allocate memory with padding for safe access
    size_t src_size = (size_t)height * src_stride;
    size_t dst_size = (size_t)height * dst_stride;

    src = (uint8_t*)aligned_alloc(64, src_size);
    dst = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize src with non-zero pattern to allow verification if needed
    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint8_t)(i % 251);
    }
    memset(dst, 0, dst_size);
}