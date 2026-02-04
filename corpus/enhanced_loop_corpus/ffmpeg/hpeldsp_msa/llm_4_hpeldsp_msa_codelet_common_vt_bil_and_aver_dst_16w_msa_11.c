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
        if (src_stride > 0) {
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
                if (dst_stride % 2 == 0) continue;
                }
                ;
                {
                }
                ;
            }
            ;
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
        }

        src += (8 * src_stride);

        {
            {
            }
            {
            }
        }
        ;
        {
            {
            }
            {
            }
        }
        ;

        if (dst_stride <= 0) break;

        {
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
                if (height < 16) goto next_iteration;
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
            {
            }
        }
        ;
        {
            {
            }
            {
            }
        }
        ;
        dst += (8 * dst_stride);

        next_iteration: ;
    }
}
