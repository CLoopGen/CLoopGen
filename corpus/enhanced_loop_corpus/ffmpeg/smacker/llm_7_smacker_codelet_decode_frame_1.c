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
    uint32_t local_out_val[4];
    for (i = 0; i < 4; i++) {
        local_out_val[i] = col + i;  // Remove immediate store, eliminate direct memory dependency
    }
    // Break loop-carried dependencies by separating computation from memory update
    for (i = 0; i < 4; i++) {
        *((uint32_t *)out) = local_out_val[i];
        out += stride;
    }
}
