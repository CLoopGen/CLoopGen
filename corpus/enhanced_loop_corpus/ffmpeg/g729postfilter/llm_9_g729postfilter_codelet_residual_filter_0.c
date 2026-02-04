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
    for (i = 0; i < 6; i++)
        sum += filter_coeffs[i] * in[n - i - 1];
    sum += (filter_coeffs[0] + filter_coeffs[5]) * (in[n - 3] + 1); 
    out[n] = in[n] + ((sum + 512) >> 10);
}
}
