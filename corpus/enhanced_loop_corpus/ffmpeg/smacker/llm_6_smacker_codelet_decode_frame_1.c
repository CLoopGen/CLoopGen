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
    uint32_t temp_col = col;
    for (i = 0; i < 4; i++) {
        *((uint32_t *)out) = temp_col;
        temp_col += 1;  // Introduce WAW dependency on temp_col and break loop-carried RAW on col
        out += stride;
    }
}
