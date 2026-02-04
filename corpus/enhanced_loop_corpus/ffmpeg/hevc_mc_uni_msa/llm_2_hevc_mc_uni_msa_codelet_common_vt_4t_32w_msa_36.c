#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + dst_stride;

    {
        for (int i = 0; i < 4; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        for (int i = 4; i < 8; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        for (int i = 8; i < 12; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        {
            for (int i = 12; i < 16; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
        {
            for (int i = 13; i < 16; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
    }
    ;
    {
        {
            for (int i = 16; i < 20; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
        {
            for (int i = 17; i < 20; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
    }
    ;
    {
        for (int i = 20; i < 24; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    src += (2 * src_stride);
    {
        for (int i = 24; i < 28; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        for (int i = 28; i < 32; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        for (int i = 32; i < 36; ++i) {
            dst1[i] = src1[i];
            dst2[i] = src2[i];
        }
    }
    ;
    {
        {
            for (int i = 36; i < 40; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
        {
            for (int i = 37; i < 40; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
    }
    ;
    {
        {
            for (int i = 40; i < 44; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
        {
            for (int i = 41; i < 44; i += 2) {
                dst1[i] = src1[i];
                dst2[i] = src2[i];
            }
        }
        ;
    }
    ;
    dst += 2 * dst_stride;
}
}
