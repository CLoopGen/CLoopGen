#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 2;
    int remainder = len % unroll_factor;
    // Handle full unrolled iterations
    for (j = 0; j < len - remainder; j += unroll_factor) {
        for (i = 0; i < channels; i++) {
            (*samples++) = (int)((unsigned int)in[i][j] << shift);
            (*samples++) = (int)((unsigned int)in[i][j + 1] << shift);
        }
    }
    // Handle leftover iteration
    for (; j < len; j++) {
        for (i = 0; i < channels; i++) {
            (*samples++) = (int)((unsigned int)in[i][j] << shift);
        }
    }
}
