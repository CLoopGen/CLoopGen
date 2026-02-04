#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int size;
int bpp;
int i;

static uint8_t *dst_buf;
static uint8_t *src_buf;
static uint8_t *last_buf;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    bpp = 4; // bytes per pixel, chosen to allow safe indexing from i-bpp
    i = bpp; // start from bpp to avoid out-of-bounds access at i-bpp

    dst_buf = aligned_alloc(32, size * sizeof(uint8_t));
    src_buf = aligned_alloc(32, size * sizeof(uint8_t));
    last_buf = aligned_alloc(32, size * sizeof(uint8_t));

    dst = dst_buf;
    src = src_buf;
    last = last_buf;

    for (int j = 0; j < size; j++) {
        dst_buf[j] = rand() & 255;
        src_buf[j] = rand() & 255;
        last_buf[j] = rand() & 255;
    }
}