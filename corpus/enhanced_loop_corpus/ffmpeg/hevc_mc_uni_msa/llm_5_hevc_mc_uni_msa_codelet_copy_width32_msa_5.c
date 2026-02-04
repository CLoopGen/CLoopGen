#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 2); cnt--;) {
        {
            {
                if (cnt & 1)
                    goto skip_second_cleanup;
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
            {
            }
            ;
        }
        ;
        src += (4 * src_stride);
        {
            {
                if (cnt < (height >> 3))
                    goto skip_dst_update;
            }
            ;
            {
            }
            ;
        }
        ;
        dst += (4 * dst_stride);
        skip_dst_update: ;
        skip_second_cleanup: ;
    }
}
