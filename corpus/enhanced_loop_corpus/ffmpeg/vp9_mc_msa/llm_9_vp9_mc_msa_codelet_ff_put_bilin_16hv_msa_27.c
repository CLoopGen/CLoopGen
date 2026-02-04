#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = height; loop_cnt > 0; loop_cnt -= 8) {
        if (loop_cnt >= 8) {
            dst[0] = src[0];
            dst[1] = src[src_stride];
            dst[2] = src[2*src_stride];
            dst[3] = src[3*src_stride];
            dst[4] = src[4*src_stride];
            dst[5] = src[5*src_stride];
            dst[6] = src[6*src_stride];
            dst[7] = src[7*src_stride];

            src += (8 * src_stride);
            dst += (8 * dst_stride);
        } else {
            for (int i = 0; i < loop_cnt; i++) {
                dst[i * dst_stride] = src[i * src_stride];
            }
            break;
        }
    }
}
