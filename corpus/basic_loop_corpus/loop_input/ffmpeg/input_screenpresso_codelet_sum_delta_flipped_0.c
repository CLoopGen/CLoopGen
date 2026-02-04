#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_linesize;
uint8_t *src;
int src_linesize;
int bytewidth;
int height;
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;

void init_vars() {
    bytewidth = 4096;
    height = 16384;
    dst_linesize = bytewidth;
    src_linesize = bytewidth;

    size_t dst_size = (size_t)dst_linesize * (size_t)height;
    size_t src_size = (size_t)src_linesize * (size_t)height;

    internal_dst_buffer = calloc(dst_size, 1);
    if (!internal_dst_buffer) exit(1);

    internal_src_buffer = malloc(src_size);
    if (!internal_src_buffer) exit(1);

    for (size_t idx = 0; idx < src_size; idx++) {
        internal_src_buffer[idx] = rand() & 0xFF;
    }

    dst = internal_dst_buffer;
    src = internal_src_buffer;
}