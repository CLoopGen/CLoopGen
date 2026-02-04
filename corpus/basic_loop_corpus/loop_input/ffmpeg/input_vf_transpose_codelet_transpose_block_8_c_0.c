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
    w = 4096;
    h = 4096;
    src_linesize = 4096;
    dst_linesize = 4096;

    size_t src_size = (size_t)(h + 1) * (size_t)src_linesize;
    size_t dst_size = (size_t)h * (size_t)dst_linesize;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}