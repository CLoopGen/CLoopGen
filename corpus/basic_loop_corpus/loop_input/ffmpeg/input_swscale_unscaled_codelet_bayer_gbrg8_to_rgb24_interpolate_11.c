#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024ULL * 1024ULL)
#define SRC_WIDTH 256
#define SRC_HEIGHT (TOTAL_ELEMENTS / SRC_WIDTH)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    src_stride = SRC_WIDTH;
    dst_stride = SRC_WIDTH * 3; 
    width = SRC_WIDTH - 4; 

    if (width % 2 != 0) {
        width -= 1;
    }

    src_buffer = (uint8_t*)aligned_alloc(32, (size_t)(SRC_HEIGHT * src_stride * sizeof(uint8_t)));
    dst_buffer = (uint8_t*)aligned_alloc(32, (size_t)(SRC_HEIGHT * 2 * dst_stride * sizeof(uint8_t)));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < SRC_HEIGHT * src_stride; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }
    memset(dst_buffer, 0, SRC_HEIGHT * 2 * dst_stride * sizeof(uint8_t));

    src = src_buffer + 2 * src_stride + 2;
    dst = dst_buffer + 2 * dst_stride;
}