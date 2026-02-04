#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    {
        if ((cnt & 1) == 0) {
            src += (4 * src_stride);
        } else {
            dst += (4 * dst_stride);
        }
    }
}
}
