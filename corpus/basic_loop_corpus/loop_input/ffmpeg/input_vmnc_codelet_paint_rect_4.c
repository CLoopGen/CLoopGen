#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int w = 1024;
int h = 512;
int color = 0xFFAA00; // arbitrary color in 0xRRGGBB format
int stride = 4096;
int i;
int j;
uint32_t *dst2;

static uint8_t *internal_dst_buffer;

void init_vars() {
    size_t total_size = (size_t)h * (size_t)stride;
    internal_dst_buffer = aligned_alloc(32, total_size);
    if (!internal_dst_buffer) {
        exit(1);
    }
    dst = internal_dst_buffer;
}

__attribute__((destructor)) void cleanup() {
    free(internal_dst_buffer);
}