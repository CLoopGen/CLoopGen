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
    float temp;
    for (n = 0; n < buffer_length; n++) {
        temp = in[n];
        for (i = 1; i <= filter_length; i++) {
            if (n >= i) {
                temp += filter_coeffs[i - 1] * in[n - i];
            }
        }
        out[n] = temp;
    }
}
