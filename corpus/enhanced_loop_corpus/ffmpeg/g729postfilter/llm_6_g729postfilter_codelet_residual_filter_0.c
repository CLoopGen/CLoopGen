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
for (n = subframe_size - 1; n >= 0; n--) {
    int sum = 2048;
    int temp_out = 0;
    for (i = 0; i < 10; i++) {
        sum += filter_coeffs[i] * in[n - i - 1];
    }
    temp_out = in[n] + (sum >> 12);
    out[n] = temp_out;
}
}
