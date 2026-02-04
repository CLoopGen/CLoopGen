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

static uint8_t *src_buf;
static uint8_t *dst_buf;

void init_vars() {
    width = 4096;
    height = 4096;
    stride = width + 16;

    size_t src_size = (size_t)stride * height * sizeof(uint8_t);
    size_t dst_size = (size_t)stride * height * sizeof(uint8_t);

    src_buf = aligned_alloc(32, src_size);
    dst_buf = aligned_alloc(32, dst_size);

    if (!src_buf || !dst_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; ++idx) {
        src_buf[idx] = rand() % 256;
    }

    for (size_t idx = 0; idx < dst_size; ++idx) {
        dst_buf[idx] = 0;
    }

    src = src_buf;
    dst = dst_buf;
}