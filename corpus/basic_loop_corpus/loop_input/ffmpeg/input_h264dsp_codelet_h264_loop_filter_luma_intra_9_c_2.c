#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint16_t *pix;
int d;

static uint16_t *pix_data;
static ptrdiff_t total_size;

void init_vars() {
    inner_iters = 10000;
    alpha = 10;
    beta = 8;
    xstride = 1;
    ystride = 256;
    int height = 4 * inner_iters;
    int width = 1024;
    total_size = height * ystride + 4 * xstride;
    pix_data = aligned_alloc(64, total_size * sizeof(uint16_t));
    if (!pix_data) {
        exit(1);
    }
    for (ptrdiff_t i = 0; i < total_size; i++) {
        pix_data[i] = (uint16_t)(i % 256);
    }
    pix = pix_data + 3 * xstride;
}