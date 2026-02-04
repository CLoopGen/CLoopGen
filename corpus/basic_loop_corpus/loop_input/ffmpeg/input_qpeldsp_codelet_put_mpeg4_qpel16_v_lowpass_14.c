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

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of source data
#define HEIGHT 17
#define WIDTH (DATA_SIZE / HEIGHT)
#define CM_SIZE 256

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    dstStride = 1;
    srcStride = 1;
    w = WIDTH;

    // Allocate buffers
    dst_buffer = aligned_alloc(32, (size_t)HEIGHT * dstStride * sizeof(uint8_t) * w);
    src_buffer = aligned_alloc(32, (size_t)HEIGHT * srcStride * sizeof(uint8_t) * w);
    cm_buffer = malloc(CM_SIZE * sizeof(uint8_t));

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;
    cm = cm_buffer;

    // Initialize cm lookup table
    for (int idx = 0; idx < CM_SIZE; idx++) {
        cm[idx] = (uint8_t)((idx * 17 + 251) % 256);
    }

    // Initialize src with non-zero test pattern
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < w; col++) {
            src_buffer[row * srcStride + col] = (uint8_t)((row * 1000 + col) % 256);
        }
    }

    // Initialize dst to zero
    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < w; col++) {
            dst_buffer[row * dstStride + col] = 0;
        }
    }

    i = 0;
}