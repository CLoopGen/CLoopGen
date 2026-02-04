#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf2;
extern uint32_t state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t s = state;
    for (k = 0; k < 640 * 480 * 2; k += 2) {
        s = s * 1664525 + 1013904223;
        buf2[k] = s >> 24;
        s = s * 1664525 + 1013904223;
        buf2[k + 1] = s >> 24;
    }
    state = s;
}
