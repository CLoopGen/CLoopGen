#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *nextband;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (g = 0; g < 128; g += 2) {
    nextband[g] = g;
    if (g + 1 < 128)
        nextband[g + 1] = g + 1;
}
}
