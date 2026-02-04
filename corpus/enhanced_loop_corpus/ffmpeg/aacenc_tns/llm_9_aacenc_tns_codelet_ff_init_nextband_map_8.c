#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (g = 0; g < 64; g++) {
        nextband[g * 2] = g;
        nextband[g * 2 + 1] = g + 128;
    }
}
