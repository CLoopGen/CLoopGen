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
    if (i % 4 == 0) {
        dst += dst_stride;
        continue;
    }
    if (i < 8) {
        dst += dst_stride * 2;
    } else {
        dst += dst_stride / 2;
    }
    dst += dst_stride;
}
}
