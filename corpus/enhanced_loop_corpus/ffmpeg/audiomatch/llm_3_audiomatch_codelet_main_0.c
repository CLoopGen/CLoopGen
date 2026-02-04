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
    // Variant 2: Reverse Consecutive Memory Access (iterate from end to start)
    for (i = siglen - 1; i >= 0; i--) {
        signal[i] = ((uint8_t *)(signal + i))[0] + 256 * ((uint8_t *)(signal + i))[1];
        sigamp += signal[i] * signal[i];
    }
}
