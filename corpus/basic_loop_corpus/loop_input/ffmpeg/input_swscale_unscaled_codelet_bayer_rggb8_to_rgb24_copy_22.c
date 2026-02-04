#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (128 * 1024 * 1024)

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    src_stride = 1024;
    dst_stride = 1024;
    width = 64;

    size_t src_size = (size_t)(width / 2 + 1) * 2 * src_stride * sizeof(uint8_t);
    size_t dst_size = (size_t)(width / 2) * 6 + 2 * dst_stride * 3 * sizeof(uint8_t);

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src_buffer, 0, src_size);
    memset(dst_buffer, 0, dst_size);

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}

void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}