#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in;
int size;
float alpha;
int i;
float gain_scale_factor;
float mem;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float);
    in = (float *)aligned_alloc(32, size * sizeof(float));
    out = (float *)aligned_alloc(32, size * sizeof(float));

    alpha = 0.99f;
    gain_scale_factor = 0.1f;
    mem = 0.0f;

    for (int j = 0; j < size; j++) {
        in[j] = (float)(j % 100) / 100.0f;
        out[j] = 0.0f;
    }
}