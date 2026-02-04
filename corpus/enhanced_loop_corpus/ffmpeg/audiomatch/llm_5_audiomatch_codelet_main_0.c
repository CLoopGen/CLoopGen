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
        int index = i;
        signal[index] = ((uint8_t *)(signal + index))[0] + 256 * ((uint8_t *)(signal + index))[1];
        if (signal[index] > 0) {
            sigamp += signal[index] * signal[index];
        }
    }
}
