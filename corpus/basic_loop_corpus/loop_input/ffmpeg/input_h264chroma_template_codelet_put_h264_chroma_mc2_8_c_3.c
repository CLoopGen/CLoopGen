#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int B;
int C;
int D;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    A = 16;
    B = 32;
    C = 48;
    D = 64;
    h = 8192;
    stride = 16384;

    size_t src_size = (h + 1) * stride + 4;
    size_t dst_size = h * stride;

    src_buffer = aligned_alloc(32, src_size * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}