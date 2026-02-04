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
    uint8_t *src0 = src;
    uint8_t *src1 = src + src_stride;
    uint8_t *src2 = src + 2*src_stride;
    uint8_t *src3 = src + 3*src_stride;
    uint8_t *src4 = src + 4*src_stride;
    uint8_t *src5 = src + 5*src_stride;
    uint8_t *src6 = src + 6*src_stride;
    uint8_t *src7 = src + 7*src_stride;

    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + dst_stride;
    uint8_t *dst2 = dst + 2*dst_stride;
    uint8_t *dst3 = dst + 3*dst_stride;
    uint8_t *dst4 = dst + 4*dst_stride;
    uint8_t *dst5 = dst + 5*dst_stride;
    uint8_t *dst6 = dst + 6*dst_stride;
    uint8_t *dst7 = dst + 7*dst_stride;

    {
        {
            {
                dst0[0] = src0[0]; dst0[1] = src0[1];
                dst1[0] = src1[0]; dst1[1] = src1[1];
                dst2[0] = src2[0]; dst2[1] = src2[1];
                dst3[0] = src3[0]; dst3[1] = src3[1];
            }
            ;
            {
                dst4[0] = src4[0]; dst4[1] = src4[1];
                dst5[0] = src5[0]; dst5[1] = src5[1];
                dst6[0] = src6[0]; dst6[1] = src6[1];
                dst7[0] = src7[0]; dst7[1] = src7[1];
            }
            ;
        }
        ;
        {
            {
                dst0[2] = src0[2]; dst0[3] = src0[3];
                dst1[2] = src1[2]; dst1[3] = src1[3];
                dst2[2] = src2[2]; dst2[3] = src2[3];
                dst3[2] = src3[2]; dst3[3] = src3[3];
            }
            ;
            {
                dst4[2] = src4[2]; dst4[3] = src4[3];
                dst5[2] = src5[2]; dst5[3] = src5[3];
                dst6[2] = src6[2]; dst6[3] = src6[3];
                dst7[2] = src7[2]; dst7[3] = src7[3];
            }
            ;
        }
        ;
    }
    ;
    {
        {
            {
                dst0[4] = src0[4]; dst0[5] = src0[5];
                dst1[4] = src1[4]; dst1[5] = src1[5];
                dst2[4] = src2[4]; dst2[5] = src2[5];
                dst3[4] = src3[4]; dst3[5] = src3[5];
            }
            ;
            {
                dst4[4] = src4[4]; dst4[5] = src4[5];
                dst5[4] = src5[4]; dst5[5] = src5[5];
                dst6[4] = src6[4]; dst6[5] = src6[5];
                dst7[4] = src7[4]; dst7[5] = src7[5];
            }
            ;
        }
        ;
        {
            {
                dst0[6] = src0[6]; dst0[7] = src0[7];
                dst1[6] = src1[6]; dst1[7] = src1[7];
                dst2[6] = src2[6]; dst2[7] = src2[7];
                dst3[6] = src3[6]; dst3[7] = src3[7];
            }
            ;
            {
                dst4[6] = src4[6]; dst4[7] = src4[7];
                dst5[6] = src5[6]; dst5[7] = src5[7];
                dst6[6] = src6[6]; dst6[7] = src6[7];
                dst7[6] = src7[6]; dst7[7] = src7[7];
            }
            ;
        }
        ;
    }
    ;

    src += 8 * src_stride;
    dst += 8 * dst_stride;
}
}
