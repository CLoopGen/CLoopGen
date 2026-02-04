#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

ptrdiff_t xstride;
ptrdiff_t ystride;
int inner_iters;
int alpha;
int beta;
uint16_t *pix;

int d;

void init_vars() {
    inner_iters = 10000;
    alpha = 10;
    beta = 5;
    xstride = 16;
    ystride = 1;

    const ptrdiff_t min_offset = -2 * labs(xstride);
    const ptrdiff_t max_offset = 1 * labs(xstride);
    const ptrdiff_t total_span = (max_offset - min_offset) + 1;
    const int base_size = 4 * inner_iters * (int)labs(ystride) + 1;

    const size_t data_size = base_size + (size_t)(total_span);
    uint16_t *data = aligned_alloc(32, data_size * sizeof(uint16_t));
    if (!data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        data[i] = rand() % 256;
    }

    pix = data - min_offset;
}