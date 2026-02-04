#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[16];
    for (uint32_t i = 0; i < 16; i++) {
        indices[i] = (15 - i) * stride;
    }
    for (row = 16; row--;) {
        dst += indices[15 - row];
    }
}
