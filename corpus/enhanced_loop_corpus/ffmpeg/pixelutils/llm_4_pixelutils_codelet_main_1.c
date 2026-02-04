#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf1;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 320 * 240; k++) {
        state = state * 1664525 + 1013904223;
        if ((k & 63) != 0) {
            buf1[k] = state >> 24;
        }
    }
}
