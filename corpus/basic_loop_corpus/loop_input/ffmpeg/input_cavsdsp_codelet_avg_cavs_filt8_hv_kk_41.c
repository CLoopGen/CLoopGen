#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime on modern CPU

static uint8_t *dst_buffer;
static uint8_t *src2_buffer;
static int16_t *tmp_buffer;
static uint8_t *cm_table;

void init_vars() {
    const int block_height = 8;
    const int tmp_extra = 12; // tmp[-2..10] => need 13 elements centered at offset -2
    const int tmp_stride = 8;
    const int max_w = DATA_SIZE / (block_height * sizeof(uint8_t)); // limit w by total data size

    // Allocate buffers with proper alignment and sizes
    dst_buffer = aligned_alloc(32, max_w * block_height * sizeof(uint8_t));
    src2_buffer = aligned_alloc(32, max_w * block_height * sizeof(uint8_t));
    tmp_buffer = aligned_alloc(32, (max_w + tmp_extra) * tmp_stride * sizeof(int16_t));
    cm_table = aligned_alloc(32, 1024 * sizeof(uint8_t));

    // Initialize global pointers
    dst = dst_buffer;
    src2 = src2_buffer;
    tmp = tmp_buffer + 2 * tmp_stride; // so that tmp[-2] is valid
    cm = cm_table;

    // Set strides and loop count
    dstStride = 1;
    srcStride = 1;
    w = max_w > 10000 ? 10000 : max_w; // cap w to ensure memory safety and target runtime

    // Initialize cm table: map [0, 1023] -> clipped values (e.g., identity mapped to 0-255)
    for (int idx = 0; idx < 1024; idx++) {
        cm[idx] = (uint8_t)((idx * 255) / 1023);
    }

    // Initialize input buffers to non-zero predictable patterns
    for (int j = 0; j < w * block_height; j++) {
        dst_buffer[j] = (uint8_t)(j % 256);
        src2_buffer[j] = (uint8_t)((j * 7) % 256);
    }

    for (int j = 0; j < (w + tmp_extra) * tmp_stride; j++) {
        tmp_buffer[j] = (int16_t)((j * 3) % 512 - 256);
    }

    // Initialize i
    i = 0;
}