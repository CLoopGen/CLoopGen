#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + (2 * src_stride);
    uint8_t *src3 = src + (3 * src_stride);
    
    dst[0] = src0[0];
    dst[1] = src1[0];
    dst[2] = src2[0];
    dst[3] = src3[0];

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
