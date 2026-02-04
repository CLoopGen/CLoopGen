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
    for (; n < buffer_length; n += 2) {
        if (n < buffer_length) {
            out[n] = in[n];
            for (i = 1; i <= filter_length && (n - i) >= 0; i++)
                out[n] -= filter_coeffs[i - 1] * out[n - i];
        }
        if (n + 1 < buffer_length) {
            out[n + 1] = in[n + 1];
            for (i = 1; i <= filter_length && (n + 1 - i) >= 0; i++)
                out[n + 1] -= filter_coeffs[i - 1] * out[n + 1 - i];
        }
    }
}
