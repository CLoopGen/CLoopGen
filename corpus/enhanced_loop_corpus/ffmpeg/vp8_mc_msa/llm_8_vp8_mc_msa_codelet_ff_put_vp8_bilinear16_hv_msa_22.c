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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        {
            uint8_t *src1 = src;
            uint8_t *src2 = src + src_stride;
            dst[0] = (uint8_t)((src1[0] + src2[0]) >> 1);
            dst[1] = (uint8_t)((src1[1] + src2[1]) >> 1);
            dst[2] = (uint8_t)((src1[2] + src2[2]) >> 1);
            dst[3] = (uint8_t)((src1[3] + src2[3]) >> 1);
        }
        ;
        {
            uint8_t *src3 = src + (2 * src_stride);
            uint8_t *src4 = src + (3 * src_stride);
            dst[4] = (uint8_t)((src3[0] + src4[0]) >> 1);
            dst[5] = (uint8_t)((src3[1] + src4[1]) >> 1);
            dst[6] = (uint8_t)((src3[2] + src4[2]) >> 1);
            dst[7] = (uint8_t)((src3[3] + src4[3]) >> 1);
        }
        ;
        src += (4 * src_stride);
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        dst += dst_stride;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        dst += dst_stride;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        {
            dst += dst_stride;
        }
        ;
        dst += dst_stride;
    }
}
