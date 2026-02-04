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
int prev_sum = 0;
for (n = subframe_size - 1; n >= 0; n--) {
    int sum = 2048;
    if (n == subframe_size - 1) {
        for (i = 0; i < 10; i++)
            sum += filter_coeffs[i] * in[n - i - 1];
    } else {
        sum = prev_sum;
        sum -= filter_coeffs[9] * in[n - 9]; 
        sum += filter_coeffs[0] * in[n - 1]; 
        for (int shift = 9; shift > 0; shift--)
            filter_coeffs[shift] = filter_coeffs[shift-1];
    }
    out[n] = in[n] + (sum >> 12);
    prev_sum = sum;
}
}
