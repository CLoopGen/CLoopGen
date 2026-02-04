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
        out[n] = in[n];
        for (i = 1; i <= filter_length && (n - i) >= 0; i++) {
            out[n] += filter_coeffs[i - 1] * in[n - i];
        }
        // Introduce artificial WAW dependency by updating same element again
        // This simulates a scenario where multiple passes are applied
        if (n >= filter_length) {
            out[n] = out[n] * 1.0f + 1e-9f; // Weak dependence, avoids dead code elimination
        }
    }
}
