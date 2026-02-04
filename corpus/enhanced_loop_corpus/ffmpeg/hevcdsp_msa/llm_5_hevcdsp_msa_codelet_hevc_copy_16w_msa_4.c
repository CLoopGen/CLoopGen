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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        int32_t temp_src_offset = 8 * src_stride;
        int32_t temp_dst_offset = 4 * dst_stride;

        if (temp_src_offset != 0) {
            src += temp_src_offset;
        }

        {
            {
            }
            ;
            {
            }
            ;
        }

        if (loop_cnt & 1) {
            dst += temp_dst_offset;
            {
                {
                }
                ;
                {
                }
                ;
            }
        } else {
            {
                {
                }
                ;
                {
                }
                ;
            }
            dst += (2 * temp_dst_offset);
        }

        {
            {
            }
            ;
            {
            }
            ;
        }

        if (temp_dst_offset > 0) {
            dst += temp_dst_offset;
        }
    }
}
