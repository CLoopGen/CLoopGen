#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *top;
int size;
int bpp;
int i;

static uint8_t *src_buf;
static uint8_t *dst_buf;
static uint8_t *top_buf;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB data size for ~0.01 sec runtime on modern CPU
    bpp = 4; // bytes per pixel, assumed constant and safe for indexing
    i = bpp; // initialize loop index to avoid src[i - bpp] underflow

    // Allocate buffers with padding for safe access
    src_buf = aligned_alloc(32, size + bpp);
    dst_buf = aligned_alloc(32, size);
    top_buf = aligned_alloc(32, size);

    // Initialize pointers to valid regions
    src = src_buf + bpp; // allow i >= bpp and i - bpp >= 0
    dst = dst_buf;
    top = top_buf;

    // Initialize input data to prevent undefined behavior
    for (int j = 0; j < size + bpp; j++) {
        src_buf[j] = (uint8_t)(j & 0xFF);
    }
    for (int j = 0; j < size; j++) {
        top_buf[j] = (uint8_t)((j + 1) & 0xFF);
    }
}