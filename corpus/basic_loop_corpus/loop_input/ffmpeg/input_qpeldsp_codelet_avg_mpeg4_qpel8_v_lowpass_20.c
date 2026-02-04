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

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of total data

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    dstStride = 9;
    srcStride = 9;
    w = 65536; // Adjust to control loop iterations for ~0.01 sec runtime

    // Allocate buffers with sufficient size
    dst_buffer = (uint8_t*)aligned_alloc(32, (size_t)w * dstStride * sizeof(uint8_t));
    src_buffer = (uint8_t*)aligned_alloc(32, (size_t)w * 9 * sizeof(uint8_t)); // max index used: 8*srcStride
    cm_buffer = (uint8_t*)aligned_alloc(32, 512 * sizeof(uint8_t)); // cm accessed via offset, give safe margin

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;
    cm = cm_buffer;

    // Initialize dst and src with non-zero values to avoid trivial optimization
    for (int j = 0; j < w; j++) {
        for (int k = 0; k < 9; k++) {
            src_buffer[j * srcStride + k] = (uint8_t)((j + k) & 0xFF);
            dst_buffer[j * dstStride + k] = (uint8_t)((j ^ k) & 0xFF);
        }
    }

    // Initialize cm table with identity-like mapping to avoid all zeros
    for (int j = 0; j < 512; j++) {
        cm_buffer[j] = (uint8_t)(j & 0xFF);
    }
}