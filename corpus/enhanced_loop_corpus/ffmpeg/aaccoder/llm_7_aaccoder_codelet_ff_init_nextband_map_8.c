#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    nextband[0] = 0;
    for (g = 1; g < 128; g++) {
        nextband[g] = nextband[g-1] + 1;
    }
}
