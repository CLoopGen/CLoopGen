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
        int32_t offset0 = (loop_cnt % 3) ? (src_stride) : (2 * src_stride);
        int32_t offset1 = (loop_cnt % 3) ? (src2_stride) : (2 * src2_stride);
        int32_t offset_dst = (loop_cnt % 3) ? (dst_stride) : (2 * dst_stride);

        src0_ptr += offset0;
        src1_ptr += offset1;
        dst += offset_dst;

        if (loop_cnt > (height >> 3)) {
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

        src0_ptr += offset0;
        src1_ptr += offset1;
        dst += offset_dst;
    }
}
