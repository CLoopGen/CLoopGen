#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    A = 15;
    E = 17;
    h = 4096;
    stride = 4096;
    step = 2048;

    size_t src_size = (h * stride) + (step + 4);
    size_t dst_size = h * stride;

    src_buffer = aligned_alloc(32, src_size * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
}