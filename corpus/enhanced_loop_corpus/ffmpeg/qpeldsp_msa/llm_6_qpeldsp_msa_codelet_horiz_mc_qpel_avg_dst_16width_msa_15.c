#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_count = (height >> 2); loop_count--;) {
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[src_stride];
    dst[0] = temp1;
    dst[dst_stride] = temp2;
    {
    }
    ;
    {
    }
    ;
    src += (4 * src_stride);
    dst += (2 * dst_stride);
    uint8_t temp3 = src[0];
    uint8_t temp4 = src[src_stride];
    dst[0] = temp3;
    dst[dst_stride] = temp4;
    {
    }
    ;
    {
    }
    ;
    dst += (2 * dst_stride);
}
}
