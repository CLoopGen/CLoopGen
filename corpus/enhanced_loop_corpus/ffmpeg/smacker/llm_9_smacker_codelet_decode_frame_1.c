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
    for (i = 0; i < 2; i++) {
        uint32_t temp1 = col + 1;
        uint32_t temp2 = col * 2;
        *((uint32_t *)out) = temp1;
        out += stride;
        *((uint32_t *)out) = temp2;
        out += stride;
        *((uint32_t *)out) = col;
        out += stride;
        *((uint32_t *)out) = temp1 ^ temp2;
        out += stride;
    }
}
