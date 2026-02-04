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
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        uint8_t skip_update = ((intptr_t)src & 0x7) == 0;
        if (!skip_update) {
            src += src_stride;
            continue;
        }
        dst += dst_stride;
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
        src += src_stride;
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
        dst += dst_stride;
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
}
