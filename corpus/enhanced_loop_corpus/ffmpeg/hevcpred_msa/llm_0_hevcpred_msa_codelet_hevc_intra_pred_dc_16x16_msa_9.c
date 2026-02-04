#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t outer = 0; outer < 4; ++outer) {
        for (row = 4; row--; ) {
            dst += stride;
        }
    }
}
