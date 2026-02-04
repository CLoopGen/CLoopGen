#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height / 4); cnt-- > 0;) {
        uint8_t *temp_src = src;
        uint8_t *temp_dst = dst;
        uint8_t *temp_dup = dst_dup;

        if (temp_src != NULL && temp_dst != NULL) {
            src += (4 * src_stride);
            dst += (4 * dst_stride);
        }

        if (temp_dup) {
            dst_dup += (4 * dst_stride);
        } else {
            cnt -= 1;
        }

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

        if (cnt < (height / 8)) {
            src += src_stride;
            dst += dst_stride;
        }
    }
}
