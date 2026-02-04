#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *filter_coeffs;
extern  float *in;
extern int buffer_length;
extern int filter_length;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < buffer_length; n += 2) {
    float sum0 = in[n];
    float sum1 = (n + 1 < buffer_length) ? in[n + 1] : 0.0f;
    for (i = 1; i <= filter_length; i++) {
        sum0 += filter_coeffs[i - 1] * in[n - i];
        if (n + 1 < buffer_length) {
            sum1 += filter_coeffs[i - 1] * in[n + 1 - i];
        }
    }
    out[n] = sum0;
    if (n + 1 < buffer_length) {
        out[n + 1] = sum1;
    }
}
}
