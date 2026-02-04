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
for (i = 1; i <= filter_length; i++) {
    for (n = i; n < buffer_length; n++) {
        out[n] = in[n] + filter_coeffs[i - 1] * in[n - i];
    }
}
for (n = 0; n < buffer_length; n++) {
    if (n < filter_length) {
        float temp = in[n];
        for (int j = 1; j <= n; j++) {
            temp += filter_coeffs[j - 1] * in[n - j];
        }
        out[n] = temp;
    }
}
}
