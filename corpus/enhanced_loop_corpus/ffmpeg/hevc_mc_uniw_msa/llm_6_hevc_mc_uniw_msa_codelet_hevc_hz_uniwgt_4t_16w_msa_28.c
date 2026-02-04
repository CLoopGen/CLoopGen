#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    uint32_t temp1, temp2, temp3, temp4;
    uint8_t *s0 = src;
    uint8_t *s1 = src + src_stride;
    uint8_t *s2 = src + 2*src_stride;
    uint8_t *s3 = src + 3*src_stride;
    uint8_t *d0 = dst;
    uint8_t *d1 = dst + dst_stride;
    uint8_t *d2 = dst + 2*dst_stride;
    uint8_t *d3 = dst + 3*dst_stride;

    temp1 = s0[0] + s1[1];
    temp2 = s1[0] + s2[1];  
    temp3 = s2[0] + s3[1];
    temp4 = s3[0] + s0[1];

    d0[0] = (uint8_t)(temp1 & 0xFF);
    d1[1] = (uint8_t)(temp2 & 0xFF);
    d2[0] = (uint8_t)(temp3 & 0xFF);
    d3[1] = (uint8_t)(temp4 & 0xFF);

    temp1 = s0[2] ^ s2[3];
    temp2 = s1[2] ^ s3[3];
    temp3 = s2[2] ^ s0[3];
    temp4 = s3[2] ^ s1[3];

    d0[2] = (uint8_t)(temp1 & 0xFF);
    d1[3] = (uint8_t)(temp2 & 0xFF);
    d2[2] = (uint8_t)(temp3 & 0xFF);
    d3[3] = (uint8_t)(temp4 & 0xFF);

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
