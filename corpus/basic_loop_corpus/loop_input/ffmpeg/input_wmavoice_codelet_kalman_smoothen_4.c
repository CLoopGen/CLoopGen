#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
float *out;
int size;
int n;
float dot;
float *best_hist_ptr;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float); // ~256 MB of total float data
    in = (float *)aligned_alloc(32, size * sizeof(float));
    out = (float *)aligned_alloc(32, size * sizeof(float));
    best_hist_ptr = (float *)aligned_alloc(32, size * sizeof(float));

    dot = 0.75f;

    for (int i = 0; i < size; i++) {
        in[i] = (float)(i % 1000) / 100.0f;
        best_hist_ptr[i] = (float)((i + 100) % 1000) / 100.0f;
        out[i] = 0.0f;
    }
}