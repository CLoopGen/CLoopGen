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
for (loop_cnt = height; loop_cnt--;) {
    uint32_t temp1, temp2, temp3, temp4;
    for (int i = 0; i < 4; ++i) {
        temp1 = src[i * src_stride / 4] + 1;
        temp2 = src[i * src_stride / 4 + 1] * 2;
        temp3 = src[i * src_stride / 4 + 2] + temp1;
        temp4 = (temp2 ^ temp3) & 0xFF;
        dst[i * dst_stride / 4] = (uint8_t)(temp4 ^ temp1);
    }
    src += src_stride;
    dst += dst_stride;
}
}
