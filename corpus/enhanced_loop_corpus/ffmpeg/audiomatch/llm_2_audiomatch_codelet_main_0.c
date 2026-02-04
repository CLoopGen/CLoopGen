#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int siglen;
extern double sigamp;
extern int16_t *signal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (step by 2, then handle remainder)
    int stride = 2;
    int j;
    for (j = 0; j < siglen; j += stride) {
        int idx = j;
        if (idx < siglen) {
            signal[idx] = ((uint8_t *)(signal + idx))[0] + 256 * ((uint8_t *)(signal + idx))[1];
            sigamp += signal[idx] * signal[idx];
        }
        idx = j + 1;
        if (idx < siglen) {
            signal[idx] = ((uint8_t *)(signal + idx))[0] + 256 * ((uint8_t *)(signal + idx))[1];
            sigamp += signal[idx] * signal[idx];
        }
    }
}
