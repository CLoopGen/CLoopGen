#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint32_t temp1, temp2, temp3, temp4;
        for (int i = 0; i < 4; ++i) {
            temp1 = src[i * src_stride] + 1;
            temp2 = src[i * src_stride + 1] + 2;
            temp3 = src[i * src_stride + 2] + 3;
            temp4 = src[i * src_stride + 3] + 4;
            dst[i * dst_stride] = (uint8_t)(temp1 ^ temp2 ^ temp3 ^ temp4);
        }
        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
