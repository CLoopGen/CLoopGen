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
static size_t total_size;

void init_vars() {
    inner_iters = 1000000;
    alpha = 8;
    beta = 4;
    xstride = 1;
    ystride = 16;

    total_size = 4 * inner_iters * ystride + 8 * xstride;
    pix_data = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!pix_data) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        pix_data[i] = (uint16_t)(i % 256);
    }

    pix = pix_data + 4 * xstride;
}

void cleanup_vars() {
    free(pix_data);
    pix_data = NULL;
    pix = NULL;
}