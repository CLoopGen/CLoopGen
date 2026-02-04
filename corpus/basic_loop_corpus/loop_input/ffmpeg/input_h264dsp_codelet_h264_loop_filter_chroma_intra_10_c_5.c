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

uint16_t *pix_data;

void init_vars() {
    inner_iters = 10000;
    xstride = 4;
    ystride = 16;
    alpha = 10;
    beta = 5;

    size_t total_size = (size_t)(4 * inner_iters) * (size_t)ystride + 2 * (size_t)abs(xstride);
    pix_data = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!pix_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    pix = pix_data + abs(xstride); 
}