#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *out;
float *filter_coeffs;
float *in;
int buffer_length;
int filter_length;
int i;
int n;

void init_vars() {
    filter_length = 64;
    buffer_length = (1 << 20); // ~4MB of output data (1M floats)

    in = (float*)aligned_alloc(32, buffer_length * sizeof(float));
    out = (float*)aligned_alloc(32, buffer_length * sizeof(float));
    filter_coeffs = (float*)aligned_alloc(32, filter_length * sizeof(float));

    for (int j = 0; j < buffer_length; j++) {
        in[j] = ((float)rand() / (float)RAND_MAX) * 2.0f - 1.0f;
    }
    for (int j = 0; j < filter_length; j++) {
        filter_coeffs[j] = ((float)rand() / (float)RAND_MAX) * 0.1f;
    }

    i = 0;
    n = filter_length; // ensure n-i >= 0 in loop
}