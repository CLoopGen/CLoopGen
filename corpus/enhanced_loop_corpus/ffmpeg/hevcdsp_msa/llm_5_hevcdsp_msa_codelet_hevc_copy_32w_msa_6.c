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
        {
            {
            }
            ;
        }
        ;
        if (loop_cnt > (height >> 3)) {
            {
                {
                }
                ;
            }
            ;
            src += (4 * src_stride);
            dst += dst_stride;
            {
                {
                }
                ;
            }
            ;
            dst += dst_stride;
        } else {
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
            }
            ;
            src += (4 * src_stride);
            dst += dst_stride;
            dst += dst_stride;
        }
        {
            {
            }
            ;
        }
        ;
        if (loop_cnt < (height >> 4)) {
            dst += dst_stride;
            {
                {
                }
                ;
            }
            ;
            continue;
        }
        dst += dst_stride;
        {
            {
            }
            ;
        }
        ;
        dst += dst_stride;
    }
}
