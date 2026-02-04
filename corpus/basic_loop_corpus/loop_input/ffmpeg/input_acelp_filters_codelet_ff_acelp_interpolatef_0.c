#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in;
float *filter_coeffs;
int precision;
int frac_pos;
int filter_length;
int length;
int n;
int i;

void init_vars() {
    length = 1 << 20; // ~1M elements to target ~0.01 sec runtime
    filter_length = 16;
    precision = 4;
    frac_pos = 2;

    in = (float*)aligned_alloc(32, sizeof(float) * (length + filter_length));
    out = (float*)aligned_alloc(32, sizeof(float) * length);
    filter_coeffs = (float*)aligned_alloc(32, sizeof(float) * (filter_length * precision));

    for (int j = 0; j < length + filter_length; j++) {
        in[j] = (float)(j % 127) / 127.0f;
    }
    for (int j = 0; j < filter_length * precision; j++) {
        filter_coeffs[j] = (float)(j % 255) / 255.0f;
    }
    for (int j = 0; j < length; j++) {
        out[j] = 0.0f;
    }

    n = 0;
    i = 0;
}