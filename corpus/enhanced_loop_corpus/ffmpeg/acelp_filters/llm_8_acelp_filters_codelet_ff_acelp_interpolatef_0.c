#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float *filter_coeffs;
extern int precision;
extern int frac_pos;
extern int filter_length;
extern int length;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < length; n++) {
    float v = 0;
    int unrolled_count = filter_length - (filter_length % 4);
    for (i = 0; i < unrolled_count; i += 4) {
        int idx0 = i * precision;
        int idx1 = (i + 1) * precision;
        int idx2 = (i + 2) * precision;
        int idx3 = (i + 3) * precision;
        v += in[n + i] * filter_coeffs[idx0 + frac_pos];
        v += in[n + i + 1] * filter_coeffs[idx1 + frac_pos];
        v += in[n + i + 2] * filter_coeffs[idx2 + frac_pos];
        v += in[n + i + 3] * filter_coeffs[idx3 + frac_pos];
        v += in[n - i] * filter_coeffs[idx0 - frac_pos];
        v += in[n - (i + 1)] * filter_coeffs[idx1 - frac_pos];
        v += in[n - (i + 2)] * filter_coeffs[idx2 - frac_pos];
        v += in[n - (i + 3)] * filter_coeffs[idx3 - frac_pos];
    }
    for (; i < filter_length; i++) {
        int idx = i * precision;
        v += in[n + i] * filter_coeffs[idx + frac_pos];
        v += in[n - i] * filter_coeffs[idx - frac_pos];
    }
    out[n] = v;
}
}
