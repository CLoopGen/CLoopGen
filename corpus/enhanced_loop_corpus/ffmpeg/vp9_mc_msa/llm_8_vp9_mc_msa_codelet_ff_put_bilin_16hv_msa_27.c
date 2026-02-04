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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint32_t temp1 = 0, temp2 = 0, temp3 = 0;
        for (int i = 0; i < 4; i++) {
            temp1 += src[i * src_stride];
            temp2 += src[i * src_stride + 1];
            temp3 += src[i * src_stride + 2];
        }
        dst[0] = (uint8_t)(temp1 >> 2);
        dst[1] = (uint8_t)(temp2 >> 2);
        dst[2] = (uint8_t)(temp3 >> 2);

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
