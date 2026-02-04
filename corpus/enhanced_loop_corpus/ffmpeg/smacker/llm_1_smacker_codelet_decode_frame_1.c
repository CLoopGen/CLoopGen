#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2) {
        *((uint32_t *)out) = col;
        out += stride;
        if (i + 1 < 4) {
            *((uint32_t *)out) = col;
            out += stride;
        }
    }
}
