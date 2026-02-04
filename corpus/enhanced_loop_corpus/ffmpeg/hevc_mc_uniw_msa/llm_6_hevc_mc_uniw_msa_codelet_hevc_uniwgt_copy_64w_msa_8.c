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
    uint32_t temp1, temp2;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        temp1 = src[0] + src[src_stride];
        temp2 = src[1] + src[src_stride + 1];
        
        dst[0] = (uint8_t)(temp1 >> 1);
        dst[1] = (uint8_t)(temp2 >> 1);
        
        temp1 = src[2] + src[src_stride + 2];
        temp2 = src[3] + src[src_stride + 3];
        
        dst[2] = (uint8_t)(temp1 >> 1);
        dst[3] = (uint8_t)(temp2 >> 1);

        src += src_stride << 1;
        dst += dst_stride << 1;
    }
}
