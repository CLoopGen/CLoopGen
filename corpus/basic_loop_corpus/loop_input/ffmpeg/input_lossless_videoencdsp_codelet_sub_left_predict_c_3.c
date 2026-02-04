#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
ptrdiff_t width;
int height;
int i;
int j;
uint8_t prev;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 4096;
    height = 64;
    stride = width;
    prev = 0;

    size_t src_size = (size_t)stride * height;
    size_t dst_size = (size_t)width * height;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;
}