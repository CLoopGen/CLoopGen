#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int gain;
extern int *rseed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < (60 << 2); i += 2) {
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i] = gain * *rseed >> 15;
        // Second access in the stride
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i+1] = gain * *rseed >> 15;
    }
}
