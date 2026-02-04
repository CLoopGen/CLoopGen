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
    int32_t i;
    for (i = 0; i < 4; ++i) {
        dst[i] = (int16_t)(src[i] * 2 + 1);
    }
    src += src_stride;
    dst += dst_stride;
}
}
