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
    uint32_t i;
    int16_t temp1, temp2;
    for (i = 0; i < (height >> 1); ++i) {
        temp1 = (int16_t)(src[0] + src[src_stride]);
        temp2 = (int16_t)(src[1] + src[src_stride + 1]);

        dst[0] = temp1;
        dst[dst_stride] = temp2;

        src += (2 * src_stride);
        dst += (2 * dst_stride);
    }
}
