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
    int n, i, j;
    for (n = subframe_size - 1; n >= 0; n--) {
        int sum = 2048;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 5; j++) {
                int idx = i * 5 + j;
                sum += filter_coeffs[idx] * in[n - idx - 1];
            }
        }
        out[n] = in[n] + (sum >> 12);
    }
}
