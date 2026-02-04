#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int num_pixels;
uint8_t *palette;
int i;

static uint8_t *src_buf;
static uint8_t *dst_buf;
static uint8_t *palette_buf;

void init_vars() {
    size_t src_size = 64 << 20; // 64 MB for src
    num_pixels = (int)(src_size);
    size_t dst_size = num_pixels * 3;
    size_t palette_size = 256 * 4;

    src_buf = aligned_alloc(32, src_size);
    dst_buf = aligned_alloc(32, dst_size);
    palette_buf = aligned_alloc(32, palette_size);

    if (!src_buf || !dst_buf || !palette_buf) {
        exit(1);
    }

    src = src_buf;
    dst = dst_buf;
    palette = palette_buf;

    for (size_t j = 0; j < src_size; j++) {
        src_buf[j] = (uint8_t)(j % 256);
    }
    for (size_t j = 0; j < palette_size; j++) {
        palette_buf[j] = (uint8_t)(j % 256);
    }
}