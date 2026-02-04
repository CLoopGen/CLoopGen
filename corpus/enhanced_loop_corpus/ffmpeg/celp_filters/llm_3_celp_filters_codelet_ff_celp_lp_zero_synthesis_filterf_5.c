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
    // Variant 2: Consecutive (blocked) write access using temporary accumulation with unrolled input access
    float temp;
    for (n = 0; n < buffer_length; n++) {
        temp = in[n];
        for (i = 1; i <= filter_length; i += 2) {
            // Unroll by 2: consecutive access to filter_coeffs and in
            temp += filter_coeffs[i - 1] * in[n - i];
            if (i + 1 <= filter_length) {
                temp += filter_coeffs[i] * in[n - (i + 1)];
            }
        }
        out[n] = temp;
    }
}
