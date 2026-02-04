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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int i;
    uint8_t temp[8];
    int16_t accum[8] = {0};

    for (i = 0; i < 8; i++) {
        temp[i] = src[i * src_stride];
        accum[i] += temp[i] + 10; // Introduce RAW: accum[i] depends on temp[i]
        accum[(i+1)&7] = accum[i]; // Introduce WAW and loop-carried dependency
    }

    for (i = 0; i < 8; i++) {
        dst[i * dst_stride] = accum[i] << 2;
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
