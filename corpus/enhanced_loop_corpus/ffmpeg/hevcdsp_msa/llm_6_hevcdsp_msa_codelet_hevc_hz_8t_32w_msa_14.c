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
for (loop_cnt = height; loop_cnt--;) {
    int32_t offset = src_stride * 2;
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[offset];
    uint16_t combined = (uint16_t)(temp1 + temp2);
    {
        dst[0] = (int16_t)(combined - 128);
    }
    ;
    src += src_stride;
    dst += dst_stride;
}
}
