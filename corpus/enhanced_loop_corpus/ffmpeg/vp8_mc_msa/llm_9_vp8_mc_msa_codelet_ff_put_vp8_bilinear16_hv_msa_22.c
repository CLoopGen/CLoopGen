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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        int i;
        for (i = 0; i < 8; i += 2) {
            uint8_t val;
            val = (uint8_t)(src[i * src_stride + 0] + src[i * src_stride + 1] + 
                           src[(i+1) * src_stride + 0] + src[(i+1) * src_stride + 1] + 2) >> 2;
            dst[i * dst_stride + 0] = val;
            dst[i * dst_stride + 1] = val;

            val = (uint8_t)(src[i * src_stride + 2] + src[i * src_stride + 3] + 
                           src[(i+1) * src_stride + 2] + src[(i+1) * src_stride + 3] + 2) >> 2;
            dst[i * dst_stride + 2] = val;
            dst[i * dst_stride + 3] = val;
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
        
        for (i = 0; i < 4; ++i) {
            dst += dst_stride;
        }
    }
}
