#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int height;
int y;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    height = 16384;
    stride = 16384;
    dst_buffer = aligned_alloc(32, (size_t)height * (size_t)stride);
    src_buffer = aligned_alloc(32, (size_t)height * (size_t)stride);
    dst = dst_buffer;
    src = src_buffer;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}