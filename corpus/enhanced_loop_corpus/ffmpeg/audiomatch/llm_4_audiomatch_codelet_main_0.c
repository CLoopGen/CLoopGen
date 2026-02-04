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
    for (i = 0; i < siglen; i++) {
        if (i % 2 == 0) {
            signal[i] = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
            sigamp += signal[i] * signal[i];
        }
    }
}
