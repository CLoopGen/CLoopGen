#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t row;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;
static size_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    stride = 64;
    internal_src_buffer = calloc(total_size, sizeof(uint8_t));
    internal_dst_buffer = calloc(total_size, sizeof(uint8_t));
    if (!internal_src_buffer || !internal_dst_buffer) {
        exit(1);
    }
    src = internal_src_buffer;
    dst = internal_dst_buffer;
}