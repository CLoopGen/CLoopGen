#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int width;
int height;
ptrdiff_t stride_dst;
ptrdiff_t stride_src;
int i;
int j;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    width = 2048;
    height = 128;
    stride_dst = width;
    stride_src = width;

    size_t total_size = (size_t)width * height;

    src_buffer = calloc(total_size, sizeof(uint8_t));
    dst_buffer = calloc(total_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
}