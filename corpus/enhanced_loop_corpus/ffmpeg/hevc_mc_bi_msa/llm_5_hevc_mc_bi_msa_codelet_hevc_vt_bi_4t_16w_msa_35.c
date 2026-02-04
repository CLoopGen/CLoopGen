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
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int32_t update_src = (loop_cnt % 3) != 0;
        int32_t update_dst = (loop_cnt % 5) != 0;

        if (update_src) {
            src0_ptr += (2 * src_stride);
            src1_ptr += (2 * src2_stride);
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

        if (update_dst) {
            dst += (2 * dst_stride);
        }

        if (update_src) {
            src0_ptr += (2 * src_stride);
            src1_ptr += (2 * src2_stride);
        }

        if (update_dst) {
            dst += (2 * dst_stride);
        }
    }
}
