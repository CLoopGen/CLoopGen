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
    A = 10;
    B = 20;
    C = 30;
    D = 40;
    h = 10000;
    stride = 16;

    size_t buffer_size = (h + 1) * stride * sizeof(uint8_t);
    dst_buffer = aligned_alloc(32, buffer_size);
    src_buffer = aligned_alloc(32, buffer_size);

    dst = dst_buffer;
    src = src_buffer;

    for (size_t idx = 0; idx < buffer_size; idx++) {
        dst_buffer[idx] = rand() % 256;
        src_buffer[idx] = rand() % 256;
    }
}