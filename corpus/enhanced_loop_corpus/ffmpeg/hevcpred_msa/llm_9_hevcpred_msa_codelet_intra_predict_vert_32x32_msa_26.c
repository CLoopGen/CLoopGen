#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row--;) {
        dst[0] = dst[1] ^ dst[2];
        dst[1] = dst[2] ^ dst[0];
        dst += dst_stride;
        dst += dst_stride;
        row--; 
    }
}
