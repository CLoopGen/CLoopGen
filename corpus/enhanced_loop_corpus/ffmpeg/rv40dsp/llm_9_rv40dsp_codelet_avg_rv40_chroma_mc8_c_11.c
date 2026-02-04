#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    // Unroll by processing two rows per iteration to increase computational intensity
    if (i < h) {
        dst[0] = ((dst[0] + ((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + bias) >> 6) + 1) >> 1);
        dst[1] = ((dst[1] + ((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + bias) >> 6) + 1) >> 1);
        dst[2] = ((dst[2] + ((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + bias) >> 6) + 1) >> 1);
        dst[3] = ((dst[3] + ((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + bias) >> 6) + 1) >> 1);
        dst[4] = ((dst[4] + ((A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] + bias) >> 6) + 1) >> 1);
        dst[5] = ((dst[5] + ((A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] + bias) >> 6) + 1) >> 1);
        dst[6] = ((dst[6] + ((A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] + bias) >> 6) + 1) >> 1);
        dst[7] = ((dst[7] + ((A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] + bias) >> 6) + 1) >> 1);
    }

    if (i + 1 < h) {
        uint8_t *dst_next = dst + stride;
        uint8_t *src_next = src + stride;

        dst_next[0] = ((dst_next[0] + ((A * src_next[0] + B * src_next[1] + C * src_next[stride + 0] + D * src_next[stride + 1] + bias) >> 6) + 1) >> 1);
        dst_next[1] = ((dst_next[1] + ((A * src_next[1] + B * src_next[2] + C * src_next[stride + 1] + D * src_next[stride + 2] + bias) >> 6) + 1) >> 1);
        dst_next[2] = ((dst_next[2] + ((A * src_next[2] + B * src_next[3] + C * src_next[stride + 2] + D * src_next[stride + 3] + bias) >> 6) + 1) >> 1);
        dst_next[3] = ((dst_next[3] + ((A * src_next[3] + B * src_next[4] + C * src_next[stride + 3] + D * src_next[stride + 4] + bias) >> 6) + 1) >> 1);
        dst_next[4] = ((dst_next[4] + ((A * src_next[4] + B * src_next[5] + C * src_next[stride + 4] + D * src_next[stride + 5] + bias) >> 6) + 1) >> 1);
        dst_next[5] = ((dst_next[5] + ((A * src_next[5] + B * src_next[6] + C * src_next[stride + 5] + D * src_next[stride + 6] + bias) >> 6) + 1) >> 1);
        dst_next[6] = ((dst_next[6] + ((A * src_next[6] + B * src_next[7] + C * src_next[stride + 6] + D * src_next[stride + 7] + bias) >> 6) + 1) >> 1);
        dst_next[7] = ((dst_next[7] + ((A * src_next[7] + B * src_next[8] + C * src_next[stride + 7] + D * src_next[stride + 8] + bias) >> 6) + 1) >> 1);
    }

    dst += 2 * stride;
    src += 2 * stride;
}
}
