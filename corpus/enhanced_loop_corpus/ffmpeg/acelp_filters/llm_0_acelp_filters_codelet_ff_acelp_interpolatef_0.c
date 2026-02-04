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
    for (int step = 0; step < precision; step++) {
        int idx = step;
        for (i = 0; i < filter_length; i++) {
            v += in[n + i] * filter_coeffs[idx + frac_pos];
            if (n >= i) {
                v += in[n - i] * filter_coeffs[idx - frac_pos];
            }
            idx += precision;
        }
    }
    out[n] = v;
}
}
