#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *top;
int bpp;
int i;

static uint8_t *dst_buf;
static uint8_t *src_buf;
static uint8_t *top_buf;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    dst_buf = aligned_alloc(32, data_size);
    src_buf = aligned_alloc(32, data_size);
    top_buf = aligned_alloc(32, data_size);

    if (!dst_buf || !src_buf || !top_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        src_buf[j] = rand() % 256;
        top_buf[j] = rand() % 256;
    }

    dst = dst_buf;
    src = src_buf;
    top = top_buf;
    bpp = data_size;
}