#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_wrap;
uint8_t *src;
int src_wrap;
int width;
int height;
int w;
uint8_t *s1;
uint8_t *s2;
uint8_t *d;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    width = 1920;
    height = 1080;
    src_wrap = 1920;
    dst_wrap = 960;

    size_t src_size = (height + 1) * 2 * src_wrap;
    size_t dst_size = height * dst_wrap;

    src_buffer = aligned_alloc(32, src_size);
    dst_buffer = aligned_alloc(32, dst_size);

    src = src_buffer;
    dst = dst_buffer;

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst_buffer[i] = 0;
    }
}