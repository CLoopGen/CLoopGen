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
    for (i = 0; i < siglen && i < 1024; i++) {
        uint8_t low_byte = ((uint8_t *)(signal + i))[0];
        uint8_t high_byte = ((uint8_t *)(signal + i))[1];
        int16_t reconstructed = low_byte | (high_byte << 8);
        signal[i] = reconstructed;
        sigamp += reconstructed * reconstructed;
        sigamp += (reconstructed > 0) ? (reconstructed >> 2) : 0;
    }
}
