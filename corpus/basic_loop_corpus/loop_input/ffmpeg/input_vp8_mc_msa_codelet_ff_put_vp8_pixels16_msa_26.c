#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint8_t *src;
ptrdiff_t src_stride;
int height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    const int width = 1920;
    height = 1080;

    src_stride = width;
    dst_stride = width;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
}