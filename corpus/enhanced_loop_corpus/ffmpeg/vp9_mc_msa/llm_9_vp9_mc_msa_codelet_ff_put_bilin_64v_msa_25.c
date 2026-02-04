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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        __builtin_prefetch(src + 3 * src_stride, 0, 1);
        __builtin_prefetch(dst + 3 * dst_stride, 1, 1);

        for (int offset = 0; offset < dst_stride; offset++) {
            dst[offset] = src[offset];
            dst[dst_stride + offset] = src[src_stride + offset];
            dst[2*dst_stride + offset] = src[2*src_stride + offset];
            dst[3*dst_stride + offset] = src[3*src_stride + offset];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
