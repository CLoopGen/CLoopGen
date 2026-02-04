#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // Unroll two iterations
        // First iteration
        dst[0] = (((dst[0]) + (((A * src[0]) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + (((A * src[1]) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + (((A * src[2]) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + (((A * src[3]) + 32) >> 6) + 1) >> 1);
        dst[4] = (((dst[4]) + (((A * src[4]) + 32) >> 6) + 1) >> 1);
        dst[5] = (((dst[5]) + (((A * src[5]) + 32) >> 6) + 1) >> 1);
        dst[6] = (((dst[6]) + (((A * src[6]) + 32) >> 6) + 1) >> 1);
        dst[7] = (((dst[7]) + (((A * src[7]) + 32) >> 6) + 1) >> 1);

        uint8_t* dst_next = dst + stride;
        uint8_t* src_next = src + stride;

        // Second iteration
        dst_next[0] = (((dst_next[0]) + (((A * src_next[0]) + 32) >> 6) + 1) >> 1);
        dst_next[1] = (((dst_next[1]) + (((A * src_next[1]) + 32) >> 6) + 1) >> 1);
        dst_next[2] = (((dst_next[2]) + (((A * src_next[2]) + 32) >> 6) + 1) >> 1);
        dst_next[3] = (((dst_next[3]) + (((A * src_next[3]) + 32) >> 6) + 1) >> 1);
        dst_next[4] = (((dst_next[4]) + (((A * src_next[4]) + 32) >> 6) + 1) >> 1);
        dst_next[5] = (((dst_next[5]) + (((A * src_next[5]) + 32) >> 6) + 1) >> 1);
        dst_next[6] = (((dst_next[6]) + (((A * src_next[6]) + 32) >> 6) + 1) >> 1);
        dst_next[7] = (((dst_next[7]) + (((A * src_next[7]) + 32) >> 6) + 1) >> 1);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle leftover iteration
        dst[0] = (((dst[0]) + (((A * src[0]) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + (((A * src[1]) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + (((A * src[2]) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + (((A * src[3]) + 32) >> 6) + 1) >> 1);
        dst[4] = (((dst[4]) + (((A * src[4]) + 32) >> 6) + 1) >> 1);
        dst[5] = (((dst[5]) + (((A * src[5]) + 32) >> 6) + 1) >> 1);
        dst[6] = (((dst[6]) + (((A * src[6]) + 32) >> 6) + 1) >> 1);
        dst[7] = (((dst[7]) + (((A * src[7]) + 32) >> 6) + 1) >> 1);
        dst += stride;
        src += stride;
    }
}
}
