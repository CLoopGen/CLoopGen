#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *filter_coeffs;
int16_t *in;
int subframe_size;
int i;
int n;

void init_vars() {
    subframe_size = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    filter_coeffs = (int16_t*)aligned_alloc(32, 10 * sizeof(int16_t));
    in = (int16_t*)aligned_alloc(32, (subframe_size + 10) * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));

    for (i = 0; i < 10; i++) {
        filter_coeffs[i] = (int16_t)(i + 1);
    }

    for (i = 0; i < subframe_size + 10; i++) {
        in[i] = (int16_t)(i % 512);
    }

    for (i = 0; i < subframe_size; i++) {
        out[i] = 0;
    }
}