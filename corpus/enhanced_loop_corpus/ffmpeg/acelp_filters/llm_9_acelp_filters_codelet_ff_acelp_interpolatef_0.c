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
for (n = 0; n < length; n += 2) {
    float v0 = 0, v1 = 0;
    for (i = 0; i < filter_length; i++) {
        int idx = i * precision;
        v0 += in[n + i] * filter_coeffs[idx + frac_pos];
        v0 += in[n - i] * filter_coeffs[idx - frac_pos];
        if (n + 1 < length) {
            v1 += in[n + 1 + i] * filter_coeffs[idx + frac_pos];
            v1 += in[n + 1 - i] * filter_coeffs[idx - frac_pos];
        }
    }
    out[n] = v0;
    if (n + 1 < length) {
        out[n + 1] = v1;
    }
}
}
