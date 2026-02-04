#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t temp_src[8];
    uint8_t temp_dst[8];
    int i;
    for (i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
    }
    for (i = 0; i < 4; ++i) {
        dst[i * dst_stride] = temp_src[i];
        dst[i * dst_stride + 1] = temp_src[i + 1];
    }
    for (i = 4; i < 8; ++i) {
        dst[(i - 4) * dst_stride] = temp_src[i];
    }
    {
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
    }
    ;
    src += (8 * src_stride);
    dst += (4 * dst_stride);
    for (i = 0; i < 4; ++i) {
        dst[i * dst_stride] = temp_src[i + 4];
    }
    dst += (4 * dst_stride);
}
}
