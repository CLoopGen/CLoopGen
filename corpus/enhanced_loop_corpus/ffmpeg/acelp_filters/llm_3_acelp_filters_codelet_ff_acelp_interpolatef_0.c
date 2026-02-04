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
    int coeff_idx = frac_pos;
    for (i = 0; i < filter_length; i++) {
        int in_idx1 = n + i;
        int in_idx2 = n - i;
        v += in[in_idx1] * filter_coeffs[coeff_idx];
        v += in[in_idx2] * filter_coeffs[coeff_idx];
        coeff_idx += precision;
    }
    out[n] = v;
}
}
