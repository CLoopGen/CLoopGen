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
if (filter_length > 0) {
    for (; n < buffer_length; n++) {
        out[n] = in[n];
        int i_inner;
        for (i_inner = 1; i_inner <= filter_length; i_inner++) {
            int offset = n - i_inner;
            if (offset >= 0) {
                float temp = filter_coeffs[i_inner - 1] * out[offset];
                out[n] -= temp;
            }
        }
    }
}
}
