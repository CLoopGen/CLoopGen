#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_stride;
uint8_t *src;
int src_stride;
int w;
int h;
int x;
int y;
int pel;
int contrast;
int brightness;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    w = 4096;
    h = 4096;
    src_stride = w;
    dst_stride = w;
    contrast = 2048;
    brightness = 10;

    src_buffer = aligned_alloc(32, (size_t)h * src_stride * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, (size_t)h * dst_stride * sizeof(uint8_t));

    src = src_buffer;
    dst = dst_buffer;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            src[i * src_stride + j] = (uint8_t)((i + j) & 0xFF);
        }
    }
}