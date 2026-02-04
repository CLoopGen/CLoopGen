#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    w = 1920;
    h = 1080;
    srcStride = w + 4;
    dstStride = w + 4;

    size_t src_size = (size_t)(h + 4) * srcStride;
    size_t dst_size = (size_t)(h + 4) * dstStride;
    size_t cm_size = 256;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);
    cm_buffer = (uint8_t*)aligned_alloc(32, cm_size);

    if (!src_buffer || !dst_buffer || !cm_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() % 256;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = rand() % 256;
    }
    for (size_t idx = 0; idx < cm_size; idx++) {
        cm_buffer[idx] = idx;
    }

    src = src_buffer + (2 * srcStride) + 2;
    dst = dst_buffer + (2 * dstStride) + 2;

    cm = cm_buffer;
}