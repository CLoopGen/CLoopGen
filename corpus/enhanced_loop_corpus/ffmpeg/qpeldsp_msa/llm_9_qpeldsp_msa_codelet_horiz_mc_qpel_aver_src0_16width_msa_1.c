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
    if (height >= 8) {
        for (loop_count = (height >> 3); loop_count--;) {
            __builtin_prefetch(src + 0 * src_stride, 0, 1);
            __builtin_prefetch(dst + 0 * dst_stride, 1, 1);
            __builtin_prefetch(src + 1 * src_stride, 0, 1);
            __builtin_prefetch(dst + 1 * dst_stride, 1, 1);

            for (int unroll_factor = 0; unroll_factor < 8; unroll_factor += 2) {
                dst[0] = (src[0] + src[1]) >> 1;
                dst[1] = (src[2] + src[3]) >> 1;

                src += src_stride;
                dst += dst_stride;
            }
        }
    } else {
        for (loop_count = height; loop_count--;) {
            dst[0] = src[0];
            src += src_stride;
            dst += dst_stride;
        }
    }
}
