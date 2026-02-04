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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint32_t temp1, temp2;
        for (int i = 0; i < 2; ++i) {
            temp1 = src[0] + src[1];
            temp2 = src[2] + src[3];
            dst[0] = (uint8_t)(temp1 >> 1);
            dst[1] = (uint8_t)(temp2 >> 1);
            src += src_stride;
            dst += dst_stride;
        }
        src += 2 * src_stride;
        dst += 2 * dst_stride;
    }
}
