#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (g = 0; g < 64; g++) {
        nextband[2*g] = 2 * g;
        nextband[2*g + 1] = 2 * g + 1;
        nextband[2*g] ^= 0x01;
        nextband[2*g + 1] ^= 0x01;
    }
}
