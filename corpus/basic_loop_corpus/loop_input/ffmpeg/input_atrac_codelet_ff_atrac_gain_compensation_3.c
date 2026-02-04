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
    num_samples = 67108864; // ~256MB of float data (67M * 4 bytes * 4 arrays ≈ 256MB)
    in = (float*)aligned_alloc(32, num_samples * sizeof(float));
    prev = (float*)aligned_alloc(32, num_samples * sizeof(float));
    out = (float*)aligned_alloc(32, num_samples * sizeof(float));
    gc_scale = 0.85f;
    pos = 0;

    for (int i = 0; i < num_samples; i++) {
        in[i] = (float)(rand()) / RAND_MAX;
        prev[i] = (float)(rand()) / RAND_MAX;
    }
}