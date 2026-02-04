#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row--;) {
        for (uint32_t level = 0; level < 1; ++level) {
            dst += stride;
        }
        dst += stride;
    }
}
