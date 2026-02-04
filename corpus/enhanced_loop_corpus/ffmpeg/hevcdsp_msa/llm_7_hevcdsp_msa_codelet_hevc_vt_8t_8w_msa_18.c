#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32_t temp_accum = 0;
for (loop_cnt = (height >> 2); loop_cnt--;) {
    temp_accum += src[0]; 
    temp_accum += src[src_stride];
    temp_accum ^= src[2 * src_stride]; 
    temp_accum -= src[3 * src_stride]; 

    dst[0 * dst_stride] = (int16_t)(src[0] + temp_accum);
    dst[1 * dst_stride] = (int16_t)(src[src_stride] + temp_accum);
    dst[2 * dst_stride] = (int16_t)(src[2 * src_stride] + temp_accum);
    dst[3 * dst_stride] = (int16_t)(src[3 * src_stride] + temp_accum);

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
