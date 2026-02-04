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
static size_t buffer_size;

void init_vars() {
    width = 1920;
    height = 1080;
    stride = width + 16;

    buffer_size = (size_t)stride * height * 2;

    src_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < buffer_size / sizeof(uint8_t); idx++) {
        src_buffer[idx] = rand() % 256;
        dst_buffer[idx] = rand() % 256;
    }

    src = src_buffer;
    dst = dst_buffer;
}