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
        float acc = in[n];
        for (i = filter_length; i >= 1; i--) {
            if (n >= i) {
                acc -= filter_coeffs[i - 1] * out[n - i];
            }
        }
        out[n] = acc;
        for (i = 1; i <= filter_length && (n + i) < buffer_length; i++) {
            out[n + i] += filter_coeffs[0] * out[n]; // Introduces WAW and RAW dependencies across iterations
        }
    }
}
