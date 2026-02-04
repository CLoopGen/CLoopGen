#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *filter_coeffs;
extern  int16_t *in;
extern int subframe_size;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = subframe_size - 1; n >= 0; n -= 2) {
    int sum1 = 2048;
    int sum2 = 2048;
    for (i = 0; i < 8; i++) {
        sum1 += filter_coeffs[i] * in[n - i - 1];
        if (n > 0) {
            sum2 += filter_coeffs[i] * in[n - i - 2];
        }
    }
    out[n] = in[n] + (sum1 >> 12);
    if (n > 0) {
        out[n-1] = in[n-1] + (sum2 >> 12);
    }
}
}
