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
    for (i = 0; i < 8; i += 2) {
        *((uint32_t *)out) = col ^ (col << 1) ^ (col >> 1);
        out += stride;
        *((uint32_t *)out) = col ^ (col << 2);
        out += stride;
    }
}
