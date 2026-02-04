#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t row;

static uint8_t *internal_dst;
static uint8_t *internal_src;
static ptrdiff_t internal_stride;
static uint32_t internal_row;

void init_vars() {
    internal_stride = 64;
    internal_row = 16;
    size_t total_size = (size_t)internal_stride * internal_row;
    internal_dst = aligned_alloc(64, total_size);
    internal_src = aligned_alloc(64, total_size);
    dst = internal_dst;
    src = internal_src;
    stride = internal_stride;
    row = internal_row;
    for (size_t i = 0; i < total_size; i++) {
        internal_src[i] = (uint8_t)(i & 0xFF);
    }
}