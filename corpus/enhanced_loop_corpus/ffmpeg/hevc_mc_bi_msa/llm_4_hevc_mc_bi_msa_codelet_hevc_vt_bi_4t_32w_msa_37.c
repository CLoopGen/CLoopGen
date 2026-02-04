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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        if (loop_cnt & 1) {
            src1_ptr += src2_stride;
            src0_ptr += src_stride;
            dst += dst_stride;
            dst_tmp += dst_stride;
        } else {
            src1_ptr += (2 * src2_stride);
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            dst += (2 * dst_stride);
            {
            }
            ;
            src0_ptr += (2 * src_stride);
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
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
                        ;
                        {
                        }
                        ;
                    }
                    ;
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
            dst_tmp += (2 * dst_stride);
        }
    }
}
