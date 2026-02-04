#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_row = row;
    for (row = 16; temp_row--;) {
        dst += stride;
        row = temp_row;
    }
}
