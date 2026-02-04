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
if (siglen > 0) {
    for (i = 0; i < siglen; i += 2) {
        signal[i] = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
        sigamp += signal[i] * signal[i];
        if (i + 1 < siglen) {
            signal[i + 1] = ((uint8_t *)(signal + i + 1))[0] + 256 * ((uint8_t *)(signal + i + 1))[1];
            sigamp += signal[i + 1] * signal[i + 1];
        }
    }
}
}
