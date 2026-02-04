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
    out[n] = in[n];
    int i1;
    for (i1 = 1; i1 <= filter_length; i1++) {
        out[n] -= filter_coeffs[i1 - 1] * out[n - i1];
    }
}
}
