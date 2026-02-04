#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (g = 0; g < 64; g++) {
        uint8_t val = (g << 3) + (g % 7);
        nextband[g * 2] = val;
        nextband[g * 2 + 1] = val ^ 0xFF;
    }
}
