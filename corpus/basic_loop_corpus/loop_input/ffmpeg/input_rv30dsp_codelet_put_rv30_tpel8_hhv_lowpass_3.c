#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
    w = 2048;
    h = 2048;
    srcStride = w + 4;
    dstStride = w;

    size_t src_size = (h + 4) * srcStride;
    size_t dst_size = h * dstStride;
    size_t cm_size = 512;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);
    cm_buffer = aligned_alloc(32, cm_size);

    if (!src_buffer || !dst_buffer || !cm_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0, src_size);
    memset(dst_buffer, 0, dst_size);

    for (size_t idx = 0; idx < cm_size; idx++) {
        cm_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    for (int y = 0; y < h + 4; y++) {
        for (int x = 0; x < w + 4; x++) {
            ptrdiff_t offset = y * srcStride + x;
            if (offset < src_size) {
                src_buffer[offset] = rand() % 256;
            }
        }
    }

    src = src_buffer + (2 * srcStride) + 2;
    dst = dst_buffer;
    cm = cm_buffer + 256;
}

__attribute__((destructor)) void cleanup() {
    free(src_buffer);
    free(dst_buffer);
    free(cm_buffer);
}