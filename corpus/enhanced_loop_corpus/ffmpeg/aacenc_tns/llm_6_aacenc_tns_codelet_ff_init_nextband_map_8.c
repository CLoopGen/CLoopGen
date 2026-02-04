#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[128];
    for (g = 0; g < 128; g++) {
        temp[g] = g;
    }
    for (g = 0; g < 128; g++) {
        nextband[g] = temp[g];
    }
}
