#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src2;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int16_t *tmp;
int w;
uint8_t *cm;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of total data for meaningful runtime (~0.01s target)

static uint8_t *dst_buffer;
static uint8_t *src2_buffer;
static int16_t *tmp_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    const int max_w = DATA_SIZE / sizeof(int16_t); 
    w = max_w > 10000 ? 10000 : max_w; 

    dstStride = 1;
    srcStride = 1;

    size_t tmp_size = (w + 10) * 8 * sizeof(int16_t); 
    size_t dst_size = w * dstStride * sizeof(uint8_t);
    size_t src2_size = w * srcStride * sizeof(uint8_t);
    size_t cm_size = 1024;

    dst_buffer = aligned_alloc(32, dst_size);
    src2_buffer = aligned_alloc(32, src2_size);
    tmp_buffer = aligned_alloc(32, tmp_size);
    cm_buffer = aligned_alloc(32, cm_size);

    if (!dst_buffer || !src2_buffer || !tmp_buffer || !cm_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(dst_buffer, 0, dst_size);
    memset(src2_buffer, 0x40, src2_size);
    for (int j = 0; j < (w + 10) * 8; j++) {
        tmp_buffer[j] = rand() % 256 - 128;
    }
    for (int j = 0; j < cm_size; j++) {
        cm_buffer[j] = rand() % 256;
    }

    dst = dst_buffer;
    src2 = src2_buffer;
    tmp = tmp_buffer + 2 * 8; 
    cm = cm_buffer;

    i = 0;
}