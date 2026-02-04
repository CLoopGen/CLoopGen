#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src1;
ptrdiff_t srcStride;
int16_t *tmp;
int h = 10000;
int i;

static uint8_t src1_buf[256 * 1024 * 10]; // ~25.6 MB for src1 data
static int16_t tmp_buf[8 * 10005];      // enough for (h+5) iterations, each writing 8 elements

void init_vars() {
    srcStride = 10; // stride of 10 bytes per row
    src1 = src1_buf + 10; // offset to allow -2 index access safely at start
    tmp = tmp_buf;

    // Initialize src1 buffer with safe values to prevent out-of-bounds in loop
    memset(src1_buf, 1, sizeof(src1_buf));

    // Adjust h so that we don't go out of bounds on src1
    // Each iteration advances src1 by srcStride; we need up to src1[10] from base
    // Maximum accessed index: initial src1 + (h+5-1)*srcStride + 10
    // We have src1 starting at src1_buf + 10, so max offset is (h+4)*srcStride + 10
    ptrdiff_t max_access = (h + 4) * srcStride + 10;
    if (max_access >= (ptrdiff_t)sizeof(src1_buf)) {
        h = ((sizeof(src1_buf) - 10) / srcStride) - 4;
    }

    // Ensure tmp has enough space: 8 int16_t per iteration
    // No further action needed — tmp_buf is already sized for h=10000+5
}