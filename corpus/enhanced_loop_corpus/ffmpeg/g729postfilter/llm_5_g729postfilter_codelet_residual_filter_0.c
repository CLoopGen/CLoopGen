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
        for (i = 0; i < 10; i++) {
            if (filter_coeffs[i] == 0) continue;
            if (n - i - 1 < 0) break;
            sum += filter_coeffs[i] * in[n - i - 1];
        }
        out[n] = in[n] + (sum >> 12);
    }
}
