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
    uint8_t temp1, temp2, temp3, temp4;
    temp1 = src[0];
    temp2 = src[src_stride];
    temp3 = src[2 * src_stride];
    temp4 = src[3 * src_stride];

    dst[0] = temp1 + temp2;
    dst[dst_stride] = temp3 + temp4;
    dst[2 * dst_stride] = temp1 ^ temp3;
    dst[3 * dst_stride] = temp2 ^ temp4;

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
