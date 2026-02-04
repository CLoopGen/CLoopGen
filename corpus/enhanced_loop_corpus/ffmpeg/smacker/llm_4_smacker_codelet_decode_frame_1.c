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
    for (i = 0; i < 4; ++i) {
        if (i % 2 == 0) {
            *((uint32_t *)out) = col;
        }
        out += stride;
    }
}
