#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
uint8_t *src2;
int stride2;
int bh;
int i;
int j;
uint16_t histogram[256];
int bw_bytes;

static uint8_t *src_buffer;
static uint8_t *src2_buffer;

void init_vars() {
    bw_bytes = 4096;  
    bh = 64;
    stride = bw_bytes;
    stride2 = bw_bytes;

    src_buffer = aligned_alloc(32, (size_t)bw_bytes * bh);
    src2_buffer = aligned_alloc(32, (size_t)bw_bytes * bh);

    if (!src_buffer || !src2_buffer) {
        exit(1);
    }

    for (int idx = 0; idx < bw_bytes * bh; idx++) {
        src_buffer[idx] = rand() & 0xFF;
        src2_buffer[idx] = rand() & 0xFF;
    }

    src = src_buffer;
    src2 = src2_buffer;

    for (int idx = 0; idx < 256; idx++) {
        histogram[idx] = 0;
    }

    i = 0;
    j = 0;
}