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
static ptrdiff_t total_stride;

void init_vars() {
    inner_iters = 1000;
    alpha = 10;
    beta = 5;
    xstride = 16;
    ystride = 16;
    total_stride = 32 * sizeof(uint16_t);
    
    pix_data = (uint16_t*)aligned_alloc(32, total_stride * (4 * inner_iters + 6));
    if (!pix_data) {
        exit(1);
    }
    
    for (int i = 0; i < total_stride / sizeof(uint16_t); i++) {
        pix_data[i] = rand() & 0x3FF;
    }
    
    pix = pix_data + (3 * xstride) + (ystride * 2);
}