#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = 1;
    for (col = 16; col > 0; col--) {
        temp *= col;
        temp ^= (temp >> 3);
    }
    col = temp & 0xFFFF;
}
