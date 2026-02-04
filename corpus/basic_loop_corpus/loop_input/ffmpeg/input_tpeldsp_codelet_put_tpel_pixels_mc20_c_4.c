#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    stride = width + 32;

    size_t src_size = (size_t)stride * height;
    size_t dst_size = (size_t)stride * height;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;

    i = 0;
    j = 0;
}