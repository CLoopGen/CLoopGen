#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *samples;
float *coeff;
int nsamples;
int i;
int j;

void init_vars() {
    nsamples = 32000000; // ~128MB for float data, sufficient for ~0.01s runtime

    samples = (float*)aligned_alloc(32, (nsamples + 7) * sizeof(float));
    coeff = (float*)aligned_alloc(32, 8 * sizeof(float));

    for (int idx = 0; idx < 8; idx++) {
        coeff[idx] = 1.0f / (idx + 1);
    }

    for (int idx = 0; idx < nsamples + 7; idx++) {
        samples[idx] = (float)(rand() % 100) / 10.0f;
    }
}