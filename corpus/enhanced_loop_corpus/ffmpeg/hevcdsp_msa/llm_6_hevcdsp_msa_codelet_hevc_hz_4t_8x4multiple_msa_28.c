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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;
    
    dst[0 * dst_stride] = (int16_t)(src[0 * src_stride]);
    dst[1 * dst_stride] = (int16_t)(src[1 * src_stride]);
    dst[2 * dst_stride] = (int16_t)(src[2 * src_stride]);
    dst[3 * dst_stride] = (int16_t)(src[3 * src_stride]);

    offset_src = 4 * src_stride;
    offset_dst = 4 * dst_stride;

    src += offset_src;
    dst += offset_dst;
}
}
