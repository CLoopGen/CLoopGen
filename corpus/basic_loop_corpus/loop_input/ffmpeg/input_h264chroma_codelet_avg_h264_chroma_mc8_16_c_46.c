#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int E;
ptrdiff_t step;
int i;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16MB for sufficient runtime (~0.01 sec estimate)
    const int width = 8; // Since loop accesses indices 0..7
    h = total_data_size / (width * sizeof(uint16_t));
    stride = width;
    step = stride;
    A = 13;
    E = 19;

    dst = aligned_alloc(32, h * stride * sizeof(uint16_t));
    src = aligned_alloc(32, h * stride * sizeof(uint16_t));

    for (int i = 0; i < h * stride; i++) {
        dst[i] = (uint16_t)(i & 0x3FF);
        src[i] = (uint16_t)((i * 7) & 0x3FF);
    }
}