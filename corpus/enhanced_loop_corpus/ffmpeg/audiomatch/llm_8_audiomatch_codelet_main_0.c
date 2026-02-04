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
    int step = 2;
    for (i = 0; i < siglen; i += step) {
        if (i + 1 < siglen) {
            int16_t val1 = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
            int16_t val2 = ((uint8_t *)(signal + i + 1))[0] + 256 * ((uint8_t *)(signal + i + 1))[1];
            signal[i] = val1;
            signal[i + 1] = val2;
            sigamp += val1 * val1 + val2 * val2;
        } else {
            int16_t val = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
            signal[i] = val;
            sigamp += val * val;
        }
    }
}
