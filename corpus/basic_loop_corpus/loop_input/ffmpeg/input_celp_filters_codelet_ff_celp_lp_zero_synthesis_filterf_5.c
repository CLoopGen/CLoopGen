#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *filter_coeffs;
float *in;
int buffer_length;
int filter_length;
int i;
int n;

void init_vars() {
    buffer_length = 1 << 20; // Approximately 4MB of float data (1M elements)
    filter_length = 64;      // Typical small filter length

    in = (float*)aligned_alloc(32, buffer_length * sizeof(float));
    out = (float*)aligned_alloc(32, buffer_length * sizeof(float));
    filter_coeffs = (float*)aligned_alloc(32, filter_length * sizeof(float));

    for (int idx = 0; idx < buffer_length; idx++) {
        in[idx] = (float)(idx % 256);
    }
    for (int idx = 0; idx < filter_length; idx++) {
        filter_coeffs[idx] = (float)(1.0f / (idx + 1));
    }
    for (int idx = 0; idx < buffer_length; idx++) {
        out[idx] = 0.0f;
    }
}