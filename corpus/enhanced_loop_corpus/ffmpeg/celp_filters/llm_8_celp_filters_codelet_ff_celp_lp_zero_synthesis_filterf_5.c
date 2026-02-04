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
for (n = 0; n < buffer_length; n++) {
    out[n] = 0.0f;
    for (i = 0; i < filter_length; i++) {
        if (n >= i) {
            out[n] += filter_coeffs[i] * in[n - i];
        }
    }
}
}
