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
    h = 10000;
    stride = 16;

    size_t total_size = (h + 8) * stride;
    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size);

    dst = dst_buffer;
    src = src_buffer;

    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
        dst_buffer[idx] = 0;
    }
}