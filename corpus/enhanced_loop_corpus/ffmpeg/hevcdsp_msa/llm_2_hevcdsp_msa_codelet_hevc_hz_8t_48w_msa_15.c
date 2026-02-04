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
    dst[0] = (int16_t)(src[0]);
    dst[1] = (int16_t)(src[1]);
    dst[2] = (int16_t)(src[2]);
    dst[3] = (int16_t)(src[3]);
    src += 4;
    dst += 4;
}
}
