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
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + (2 * src_stride);
    uint8_t *src3 = src + (3 * src_stride);
    
    dst[0] = src0[0];
    dst[1] = src1[0];
    dst[2] = src2[0];
    dst[3] = src3[0];

    src += (4 * src_stride);
    dst += dst_stride;
}
}
