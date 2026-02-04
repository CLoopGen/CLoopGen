#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *dst;
uint32_t *src;
int stride;
int height;

static uint32_t *dst_buffer;
static uint32_t *src_buffer;

void init_vars() {
    height = 8192;
    stride = 1024;
    size_t num_elements = (size_t)height * (stride >> 2);
    size_t dst_size = num_elements * sizeof(uint32_t);
    size_t src_size = num_elements * sizeof(uint32_t);

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        src_buffer[i] = (uint32_t)(i * 7919);
        dst_buffer[i] = (uint32_t)(i * 5009);
    }

    dst = dst_buffer;
    src = src_buffer;
}