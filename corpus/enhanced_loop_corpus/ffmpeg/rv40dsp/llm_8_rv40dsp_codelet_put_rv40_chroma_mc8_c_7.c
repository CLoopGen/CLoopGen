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
    if (i + 1 < h) {
        // Process two rows per iteration to increase computational intensity
        // First row
        dst[0] = (((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + bias)) >> 6);
        dst[1] = (((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + bias)) >> 6);
        dst[2] = (((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + bias)) >> 6);
        dst[3] = (((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + bias)) >> 6);
        dst[4] = (((A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] + bias)) >> 6);
        dst[5] = (((A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] + bias)) >> 6);
        dst[6] = (((A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] + bias)) >> 6);
        dst[7] = (((A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] + bias)) >> 6);

        // Second row
        uint8_t *dst2 = dst + stride;
        uint8_t *src2 = src + stride;
        dst2[0] = (((A * src2[0] + B * src2[1] + C * src2[stride + 0] + D * src2[stride + 1] + bias)) >> 6);
        dst2[1] = (((A * src2[1] + B * src2[2] + C * src2[stride + 1] + D * src2[stride + 2] + bias)) >> 6);
        dst2[2] = (((A * src2[2] + B * src2[3] + C * src2[stride + 2] + D * src2[stride + 3] + bias)) >> 6);
        dst2[3] = (((A * src2[3] + B * src2[4] + C * src2[stride + 3] + D * src2[stride + 4] + bias)) >> 6);
        dst2[4] = (((A * src2[4] + B * src2[5] + C * src2[stride + 4] + D * src2[stride + 5] + bias)) >> 6);
        dst2[5] = (((A * src2[5] + B * src2[6] + C * src2[stride + 5] + D * src2[stride + 6] + bias)) >> 6);
        dst2[6] = (((A * src2[6] + B * src2[7] + C * src2[stride + 6] + D * src2[stride + 7] + bias)) >> 6);
        dst2[7] = (((A * src2[7] + B * src2[8] + C * src2[stride + 7] + D * src2[stride + 8] + bias)) >> 6);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle last row if h is odd
        dst[0] = (((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + bias)) >> 6);
        dst[1] = (((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + bias)) >> 6);
        dst[2] = (((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + bias)) >> 6);
        dst[3] = (((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + bias)) >> 6);
        dst[4] = (((A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5] + bias)) >> 6);
        dst[5] = (((A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6] + bias)) >> 6);
        dst[6] = (((A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7] + bias)) >> 6);
        dst[7] = (((A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8] + bias)) >> 6);
        dst += stride;
        src += stride;
    }
}
}
