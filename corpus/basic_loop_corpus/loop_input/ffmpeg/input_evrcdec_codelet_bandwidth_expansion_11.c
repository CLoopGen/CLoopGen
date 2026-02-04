#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *coeff;
float *inbuf;
float gamma;
double fac;
int i;

void init_vars() {
    size_t data_size = 1 << 20; // ~4MB total data, allows safe access within loop bounds

    coeff = (float*)aligned_alloc(32, data_size * sizeof(float));
    inbuf = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t idx = 0; idx < data_size; idx++) {
        inbuf[idx] = 1.0f + idx * 0.0001f;
    }

    gamma = 0.95f;
    fac = 1.0;
}

__attribute__((destructor))
static void cleanup() {
    free(coeff);
    free(inbuf);
}