#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    int32_t local_stride = stride;
    uint32_t i;
    for (i = 16; i--;) {
        local_dst += local_stride;
    }
    dst = local_dst;
}
