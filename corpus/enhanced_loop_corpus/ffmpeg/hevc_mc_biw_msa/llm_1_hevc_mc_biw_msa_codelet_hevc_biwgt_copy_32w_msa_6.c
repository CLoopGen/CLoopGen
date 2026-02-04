#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int unroll_1 = 0; unroll_1 < 2; unroll_1++) {
            for (int unroll_2 = 0; unroll_2 < 2; unroll_2++) {
                src0_ptr += src_stride;
                src1_ptr += src2_stride;
                dst += dst_stride;
            }
        }
        {
            {
                {
                }
                ;
                {
                }
                ;
                {
                    {
                    }
                    {
                    }
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
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
                {
                    {
                    }
                    {
                    }
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
            }
            ;
        }
    }
    if (height & 1) {
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
