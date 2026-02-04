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
static size_t total_size;

void init_vars() {
    width = 1920;
    height = 1080;
    stride = width + 16; // Ensure alignment padding if needed
    total_size = (size_t)stride * height * 2; // Two buffers: src and dst

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (size_t idx = 0; idx < total_size; ++idx) {
        src_buffer[idx] = rand() & 0xFF;
        dst_buffer[idx] = rand() & 0xFF;
    }

    i = 0;
    j = 0;
}