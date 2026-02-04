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
    for (; n < buffer_length; n++) {
        float sum = 0.0f;
        int start = (n >= filter_length) ? n - filter_length : 0;
        for (i = start; i < n; i++) {
            sum += filter_coeffs[n - i - 1] * out[i];
        }
        out[n] = in[n] - sum;
    }
}
