#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 16; i--;) {
    dst += dst_stride;
    if (i > 10) {
        dst += dst_stride;
    } else if (i > 5) {
        continue;
    } else {
        dst += dst_stride * 3;
    }
    {
        dst += dst_stride;
    }
}
}
