#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_linesize;
uint8_t *src;
int src_linesize;
int width;
int height;
int depth;
int step;
int comp;
int x;
int y;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    depth = 2;
    step = 3;
    comp = 1;
    width = 1024;
    height = 512;
    int pixel_size = (depth == 1) ? 1 : 2;
    dst_linesize = width * pixel_size;
    src_linesize = width * step;

    size_t dst_size = (size_t)dst_linesize * height;
    size_t src_size = (size_t)src_linesize * height;

    dst_buffer = aligned_alloc(32, dst_size);
    src_buffer = aligned_alloc(32, src_size);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i % 256);
    }

    dst = dst_buffer;
    src = src_buffer;
}