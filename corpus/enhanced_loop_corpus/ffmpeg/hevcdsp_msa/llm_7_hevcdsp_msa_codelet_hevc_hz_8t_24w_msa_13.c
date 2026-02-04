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
int32_t offset = 0;
for (loop_cnt = (height >> 1); loop_cnt--;) {
    int32_t idx_src = offset * src_stride;
    int32_t idx_dst = offset * dst_stride;
    dst[idx_dst] = (int16_t)(src[idx_src] * 2);
    dst[idx_dst + dst_stride] = (int16_t)(src[idx_src + src_stride] * 2);
    offset += 2;
}
src += height * src_stride;
dst += height * dst_stride;
}
