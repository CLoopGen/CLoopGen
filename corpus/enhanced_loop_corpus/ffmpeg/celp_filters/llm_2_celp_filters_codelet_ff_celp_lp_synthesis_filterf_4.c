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
    // Variant 1: Strided memory access with stride of 2
    // This variant processes only even indices, effectively creating a strided access pattern.
    // To maintain validity, we ensure n + 1 < buffer_length to avoid overflow in any dependency.
    for (; n < buffer_length; n += 2) {
        if (n >= filter_length) {  // Ensure sufficient history for feedback
            out[n] = in[n];
            for (i = 1; i <= filter_length; i++)
                out[n] -= filter_coeffs[i - 1] * out[n - i];
        }
    }
    // Process remaining odd index if buffer_length is odd and n was skipped
    n = (n >= buffer_length) ? n : n + 1;
    if (n < buffer_length && n >= filter_length) {
        out[n] = in[n];
        for (i = 1; i <= filter_length; i++)
            out[n] -= filter_coeffs[i - 1] * out[n - i];
    }
}
