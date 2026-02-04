#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width >> 4; cnt--;) {
        src_tmp = src;
        dst_tmp = dst;

        if (width > 32) {
            src_tmp += (8 * src_stride);
        } else {
            src_tmp += (6 * src_stride);
        }

        src_tmp += (7 * src_stride);

        for (loop_cnt = (height >> 2); loop_cnt--;) {
            src_tmp += (4 * src_stride);

            if (loop_cnt == (height >> 3)) {
                dst_tmp += (2 * dst_stride);
            }

            if (loop_cnt < (height >> 3)) {
                src_tmp -= src_stride;
                break;
            }

            dst_tmp += (4 * dst_stride);
        }

        if (cnt & 1) {
            src += 8;
            dst += 8;
        } else {
            src += 24;
            dst += 24;
        }
    }
}
