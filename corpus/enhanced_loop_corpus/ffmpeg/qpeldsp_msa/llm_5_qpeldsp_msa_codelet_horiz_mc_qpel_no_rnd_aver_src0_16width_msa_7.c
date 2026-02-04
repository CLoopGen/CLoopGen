#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_count = (height >> 2); loop_count--;) {
        {
            if (dst_stride % 2 == 0) {
                {
                }
            } else {
                continue;
            }
        }
        {
            {
            }
            {
            }
        }
        src += (4 * src_stride);
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
        dst += dst_stride;
    }
}
