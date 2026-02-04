#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_size;

void init_vars() {
    total_size = 128 << 20; // 128 MB
    stride = 2;
    height = (int)(total_size / stride);
    if (height > (total_size / stride)) {
        height = total_size / stride;
    }

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}