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
    uint8_t temp1, temp2, temp3, temp4;
    uint32_t offset_src = 0, offset_dst = 0;

    temp1 = src[0];
    temp2 = src[src_stride];
    temp3 = src[2 * src_stride];
    temp4 = src[3 * src_stride];

    dst[offset_dst] = temp1;
    dst[offset_dst + dst_stride] = temp2;
    dst[offset_dst + 2*dst_stride] = temp3;
    dst[offset_dst + 3*dst_stride] = temp4;

    offset_src += 4 * src_stride;
    src += offset_src;

    temp1 ^= temp2; 
    temp3 ^= temp4;
    temp1 += temp3;

    dst[offset_dst + dst_stride/2] = temp1;
    dst[offset_dst + dst_stride + dst_stride/2] = temp2 ^ temp1;
    dst[offset_dst + 2*dst_stride + dst_stride/2] = temp3 ^ temp2;
    dst[offset_dst + 3*dst_stride + dst_stride/2] = temp4 ^ temp3;

    dst += 4 * dst_stride;
}
}
