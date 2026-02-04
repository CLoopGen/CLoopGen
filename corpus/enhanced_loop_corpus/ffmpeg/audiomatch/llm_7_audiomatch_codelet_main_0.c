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
    sigamp = 0;
    for (i = 0; i < siglen; i++) {
        uint8_t *byte_ptr = (uint8_t *)&signal[i];
        int16_t low_byte = byte_ptr[0];
        int16_t high_byte = byte_ptr[1];
        int16_t reconstructed = low_byte | (high_byte << 8);
        signal[i] = reconstructed;
        sigamp = sigamp + ((double)reconstructed * reconstructed);
    }
}
