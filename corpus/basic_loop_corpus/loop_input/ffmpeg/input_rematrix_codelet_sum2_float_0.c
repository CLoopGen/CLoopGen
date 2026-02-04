#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef int integer;

float *out;
float *in1;
float *in2;
integer len;
int i;
float coeff1;
float coeff2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for three float arrays (approx)
    len = data_size / sizeof(float);

    in1 = (float*)aligned_alloc(32, len * sizeof(float));
    in2 = (float*)aligned_alloc(32, len * sizeof(float));
    out = (float*)aligned_alloc(32, len * sizeof(float));

    coeff1 = 1.5f;
    coeff2 = 2.5f;

    for (i = 0; i < len; i++) {
        in1[i] = (float)(i % 1000) / 100.0f;
        in2[i] = (float)((i + 50) % 1000) / 100.0f;
        out[i] = 0.0f;
    }
}