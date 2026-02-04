#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    for (cnt = 0; cnt < 4; ++cnt) {
        uint32_t temp1 = 0, temp2 = 0;
        temp1 += src[cnt * 4 + 0] * 2;
        temp2 += src[cnt * 4 + 1] + 5;
        dst[cnt * 4 + 0] = (temp1 & 0xFF);
        dst[cnt * 4 + 1] = (temp2 & 0xFF);
        temp1 += src[cnt * 4 + 2] * 3;
        temp2 += src[cnt * 4 + 3] - 2;
        dst[cnt * 4 + 2] = (temp1 % 256);
        dst[cnt * 4 + 3] = (temp2 % 256);
    }
    src += src_stride;
    dst += dst_stride;
}
}
