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
    int idx = 0;
    for (i = 0; i < filter_length; i++) {
        int read_idx = n + i;
        v += in[read_idx] * filter_coeffs[idx + frac_pos];
        idx += precision;
        read_idx = n - i - 1;
        if (read_idx >= 0) {
            v += in[read_idx] * filter_coeffs[idx - frac_pos];
        }
    }
    out[n] = v;
}
}
