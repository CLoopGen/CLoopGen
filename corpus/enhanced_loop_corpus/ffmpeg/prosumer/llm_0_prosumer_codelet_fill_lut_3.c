#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *lut;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 16; j++) {
        int i = j * 2;
        lut[i] = 425984;
        lut[i + 1] = 0;
    }
}
