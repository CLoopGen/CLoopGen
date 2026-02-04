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
        uint32_t skip_src_update = 0;
        uint32_t skip_dst_update = 0;

        if ((height % 4) == 0) {
            skip_src_update = 1;
        }

        if ((height % 6) == 0) {
            skip_dst_update = 1;
        }

        if (!skip_src_update) {
            src += (2 * src_stride);
        }

        if (!skip_dst_update) {
            dst += (2 * dst_stride);
        }

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
                {
                }
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
