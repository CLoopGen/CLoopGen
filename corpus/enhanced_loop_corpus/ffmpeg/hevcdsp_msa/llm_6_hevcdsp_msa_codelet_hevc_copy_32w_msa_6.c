#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    uint8_t temp1 = src[offset_src + 0 * src_stride];
    uint8_t temp2 = src[offset_src + 1 * src_stride];
    uint8_t temp3 = src[offset_src + 2 * src_stride];
    uint8_t temp4 = src[offset_src + 3 * src_stride];
    
    dst[offset_dst + 0] = (int16_t)temp1;
    dst[offset_dst + 1] = (int16_t)temp2;
    dst[offset_dst + 2] = (int16_t)temp3;
    dst[offset_dst + 3] = (int16_t)temp4;
    
    offset_dst += dst_stride;
    dst[offset_dst + 0] = (int16_t)temp4;
    dst[offset_dst + 1] = (int16_t)temp3;
    dst[offset_dst + 2] = (int16_t)temp2;
    dst[offset_dst + 3] = (int16_t)temp1;
    
    offset_dst += dst_stride;
    dst[offset_dst + 0] = (int16_t)(temp1 + temp2);
    dst[offset_dst + 1] = (int16_t)(temp2 + temp3);
    dst[offset_dst + 2] = (int16_t)(temp3 + temp4);
    dst[offset_dst + 3] = (int16_t)(temp4 + temp1);
    
    offset_dst += dst_stride;
    dst[offset_dst + 0] = (int16_t)(temp1 ^ temp2 ^ temp3 ^ temp4);
    dst[offset_dst + 1] = (int16_t)(temp1 << 1);
    dst[offset_dst + 2] = (int16_t)(temp2 << 1);
    dst[offset_dst + 3] = (int16_t)(temp3 << 1);
    
    src += 4 * src_stride;
    dst += 4 * dst_stride;
}
}
