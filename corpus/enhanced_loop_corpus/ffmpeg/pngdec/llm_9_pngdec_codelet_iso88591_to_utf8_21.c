#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern size_t size_in;
extern size_t i;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size_in && i < 1024; i++) {
        uint8_t shifted = in[i] >> 6;
        uint8_t masked = in[i] & 63;
        if (in[i] >= 128) {
            *(q++) = 192 | shifted;
            *(q++) = 128 | masked;
        } else if (in[i] >= 64) {
            *(q++) = 128 | masked;
        } else {
            *(q++) = in[i];
        }
    }
}
