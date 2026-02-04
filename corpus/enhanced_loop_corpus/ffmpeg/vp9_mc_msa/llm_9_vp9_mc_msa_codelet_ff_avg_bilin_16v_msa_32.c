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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];

        dst[dst_stride] = src[src_stride];
        dst[dst_stride + 1] = src[src_stride + 1];
        dst[dst_stride + 2] = src[src_stride + 2];
        dst[dst_stride + 3] = src[src_stride + 3];

        dst[2*dst_stride] = src[2*src_stride];
        dst[2*dst_stride + 1] = src[2*src_stride + 1];
        dst[2*dst_stride + 2] = src[2*src_stride + 2];
        dst[2*dst_stride + 3] = src[2*src_stride + 3];

        dst[3*dst_stride] = src[3*src_stride];
        dst[3*dst_stride + 1] = src[3*src_stride + 1];
        dst[3*dst_stride + 2] = src[3*src_stride + 2];
        dst[3*dst_stride + 3] = src[3*src_stride + 3];

        src += 4 * src_stride;
        dst += 4 * dst_stride;

        // Unrolled version processes 8 rows per iteration, so repeat once more
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];

        dst[dst_stride] = src[src_stride];
        dst[dst_stride + 1] = src[src_stride + 1];
        dst[dst_stride + 2] = src[src_stride + 2];
        dst[dst_stride + 3] = src[src_stride + 3];

        dst[2*dst_stride] = src[2*src_stride];
        dst[2*dst_stride + 1] = src[2*src_stride + 1];
        dst[2*dst_stride + 2] = src[2*src_stride + 2];
        dst[2*dst_stride + 3] = src[2*src_stride + 3];

        dst[3*dst_stride] = src[3*src_stride];
        dst[3*dst_stride + 1] = src[3*src_stride + 1];
        dst[3*dst_stride + 2] = src[3*src_stride + 2];
        dst[3*dst_stride + 3] = src[3*src_stride + 3];

        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
