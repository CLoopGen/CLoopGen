#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *in;
float *prev;
int num_samples;
float *out;
float gc_scale;
int pos;

void init_vars() {
    num_samples = 8388608;
    gc_scale = 1.5f;

    in = (float *)aligned_alloc(32, num_samples * sizeof(float));
    prev = (float *)aligned_alloc(32, num_samples * sizeof(float));
    out = (float *)aligned_alloc(32, num_samples * sizeof(float));

    for (int i = 0; i < num_samples; i++) {
        in[i] = (float)(rand() % 100) / 10.0f;
        prev[i] = (float)(rand() % 100) / 10.0f;
        out[i] = 0.0f;
    }
}