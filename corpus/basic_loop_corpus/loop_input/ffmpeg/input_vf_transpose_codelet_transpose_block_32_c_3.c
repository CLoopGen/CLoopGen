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
    w = 1024;
    h = 1024;
    src_linesize = w * 4;
    dst_linesize = w * 4;

    size_t src_size = src_linesize * h;
    size_t dst_size = dst_linesize * h;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() % 256;
    }

    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
}