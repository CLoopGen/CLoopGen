#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in1;
int16_t *in2;
int16_t coef;
int size;
int invcoef;
int i;

void init_vars() {
    size = 1 << 20; // 1 million elements, ~2MB total data

    in1 = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));
    in2 = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, size * sizeof(int16_t));

    coef = 8192;     // 0.5 in fixed point (8192/16384)
    invcoef = 8192;  // 1 - coef in fixed point scaling

    for (int j = 0; j < size; j++) {
        in1[j] = rand() % 32768;
        in2[j] = rand() % 32768;
        out[j] = 0;
    }
}