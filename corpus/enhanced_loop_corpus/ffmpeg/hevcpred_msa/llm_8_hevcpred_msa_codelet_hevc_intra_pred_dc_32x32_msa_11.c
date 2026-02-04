#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 32; row--;) {
    dst[0] = dst[stride * 2];
    dst[1] = dst[stride * 2 + 1];
    dst += stride;
    dst[0] = dst[stride * 2];
    dst[1] = dst[stride * 2 + 1];
    dst += stride;
}
}
