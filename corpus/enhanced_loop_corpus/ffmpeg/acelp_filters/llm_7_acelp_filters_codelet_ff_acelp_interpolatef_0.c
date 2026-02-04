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
    float v1 = 0, v2 = 0;
    int idx1 = 0, idx2 = precision * (filter_length - 1);
    for (i = 0; i < filter_length; i++) {
        v1 += in[n + i] * filter_coeffs[idx1 + frac_pos];
        v2 += in[n - i] * filter_coeffs[idx2 - frac_pos];
        idx1 += precision;
        idx2 -= precision;
    }
    out[n] = v1 + v2;
}
}
