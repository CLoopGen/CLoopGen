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
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + (2 * src_stride);
        uint8_t *src3 = src + (3 * src_stride);

        int16_t *dst0 = dst;
        int16_t *dst1 = dst + dst_stride;
        int16_t *dst2 = dst + (2 * dst_stride);
        int16_t *dst3 = dst + (3 * dst_stride);

        {
            {
                dst0[0] = (int16_t)src0[0];
                dst0[1] = (int16_t)src0[1];
                dst0[2] = (int16_t)src0[2];
                dst0[3] = (int16_t)src0[3];
            }
            ;
            {
                dst1[0] = (int16_t)src1[0];
                dst1[1] = (int16_t)src1[1];
                dst1[2] = (int16_t)src1[2];
                dst1[3] = (int16_t)src1[3];
            }
            ;
        }
        ;
        {
            {
                dst2[0] = (int16_t)src2[0];
                dst2[1] = (int16_t)src2[1];
                dst2[2] = (int16_t)src2[2];
                dst2[3] = (int16_t)src2[3];
            }
            ;
            {
                dst3[0] = (int16_t)src3[0];
                dst3[1] = (int16_t)src3[1];
                dst3[2] = (int16_t)src3[2];
                dst3[3] = (int16_t)src3[3];
            }
            ;
        }
        ;
        src += (4 * src_stride);
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
        {
        }
        ;
        {
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
        dst += (4 * dst_stride);
    }
}
