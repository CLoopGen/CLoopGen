#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int step = 0;
        if (loop_cnt & 1) {
            {
            }
            ;
            {
            }
            ;
            step = 1;
        } else {
            {
            }
            ;
            {
            }
            ;
            step = 2;
        }
        src += (4 * src_stride);
        if (step == 1) {
            dst += (2 * dst_stride);
        }
        dst += (2 * dst_stride);
    }
}
