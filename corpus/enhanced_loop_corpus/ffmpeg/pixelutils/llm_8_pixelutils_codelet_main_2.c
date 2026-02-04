#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf2;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 320 * 240; k++) {
        state = state * 1664525 + 1013904223;
        buf2[k * 2] = state >> 24;
        buf2[k * 2 + 1] = (state >> 16) & 0xFF;
    }
}
