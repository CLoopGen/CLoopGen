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
    double temp_sigamp = 0;
    for (i = 0; i < siglen; i++) {
        int16_t val = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
        signal[i] = val;
        temp_sigamp += val * val;
    }
    sigamp += temp_sigamp;
}
