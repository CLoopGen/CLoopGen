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

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    w = 1024;
    h = 1024;
    srcStride = w + 4;
    dstStride = w;

    size_t src_size = (h + 4) * srcStride;
    size_t dst_size = h * dstStride;
    
    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);
    cm_buffer = aligned_alloc(32, 256);

    if (!src_buffer || !dst_buffer || !cm_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer + (2 * srcStride) + 2;
    dst = dst_buffer;

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }
    for (int idx = 0; idx < 256; idx++) {
        cm_buffer[idx] = idx;
    }

    cm = cm_buffer;
}