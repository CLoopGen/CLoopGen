#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        // First row
        dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + ((((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3])) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + ((((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4])) + 32) >> 6) + 1) >> 1);
        
        // Second row
        uint8_t* dst2 = dst + stride;
        uint8_t* src2 = src + stride;
        dst2[0] = (((dst2[0]) + ((((A * src2[0] + B * src2[1] + C * src2[stride + 0] + D * src2[stride + 1])) + 32) >> 6) + 1) >> 1);
        dst2[1] = (((dst2[1]) + ((((A * src2[1] + B * src2[2] + C * src2[stride + 1] + D * src2[stride + 2])) + 32) >> 6) + 1) >> 1);
        dst2[2] = (((dst2[2]) + ((((A * src2[2] + B * src2[3] + C * src2[stride + 2] + D * src2[stride + 3])) + 32) >> 6) + 1) >> 1);
        dst2[3] = (((dst2[3]) + ((((A * src2[3] + B * src2[4] + C * src2[stride + 3] + D * src2[stride + 4])) + 32) >> 6) + 1) >> 1);

        dst += 2 * stride;
        src += 2 * stride;
    } else {
        // Handle last row if h is odd
        dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + ((((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3])) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + ((((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4])) + 32) >> 6) + 1) >> 1);
        dst += stride;
        src += stride;
    }
}
}
