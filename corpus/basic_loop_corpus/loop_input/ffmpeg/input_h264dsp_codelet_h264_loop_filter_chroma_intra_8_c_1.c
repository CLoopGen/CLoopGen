#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint8_t *pix;
int d;

uint8_t *pix_buffer;

void init_vars() {
    inner_iters = 1000;
    xstride = 16;
    ystride = 16;
    alpha = 10;
    beta = 10;

    size_t buffer_size = 256 * 1024 * 1024;
    pix_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!pix_buffer) exit(1);

    for (size_t i = 0; i < buffer_size; i++) {
        pix_buffer[i] = rand() % 256;
    }

    ptrdiff_t offset = 2 * xstride;
    pix = pix_buffer + offset;
}