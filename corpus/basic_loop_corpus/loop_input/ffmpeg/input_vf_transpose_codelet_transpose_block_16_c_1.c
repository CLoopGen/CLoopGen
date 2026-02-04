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
    h = 512;
    src_linesize = w;
    dst_linesize = w * 2;

    size_t src_size = (h + 1) * src_linesize;
    size_t dst_size = (h + 1) * dst_linesize;

    src_buffer = calloc(1, src_size);
    dst_buffer = calloc(1, dst_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (int i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
}