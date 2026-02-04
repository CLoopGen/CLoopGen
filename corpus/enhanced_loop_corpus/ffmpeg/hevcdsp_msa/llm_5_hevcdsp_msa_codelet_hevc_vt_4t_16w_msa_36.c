#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int32_t step = (height - (loop_cnt << 2)) & 4;

        src += (2 * src_stride);
        dst += dst_stride;

        if (step == 0) {
            dst += dst_stride;
        } else {
            src += (2 * src_stride);
        }

        dst += dst_stride;

        if (step != 0) {
            continue;
        }

        src += (2 * src_stride);
        dst += dst_stride;
    }
}
