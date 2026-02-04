#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t src_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
int w;
int h;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    w = 128;
    h = 100000;
    src_linesize = 128;
    dst_linesize = 1024;

    size_t src_size = h * src_linesize;
    size_t dst_size = h * dst_linesize;

    src_buffer = (uint8_t*)aligned_alloc(64, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(64, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() % 256;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}