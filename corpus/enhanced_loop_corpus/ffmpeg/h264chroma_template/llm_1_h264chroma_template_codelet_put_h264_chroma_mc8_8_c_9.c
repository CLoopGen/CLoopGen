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
            // Process two rows per iteration
            uint8_t *dst1 = dst;
            uint8_t *dst2 = dst + stride;
            uint8_t *src1 = src;
            uint8_t *src2 = src + stride;

            for (int j = 0; j < 8; j++) {
                dst1[j] = ((((A * src1[j] + B * src1[j + 1] + C * src1[stride + j] + D * src1[stride + j + 1])) + 32) >> 6);
                dst2[j] = ((((A * src2[j] + B * src2[j + 1] + C * src2[stride + j] + D * src2[stride + j + 1])) + 32) >> 6);
            }

            dst += 2 * stride;
            src += 2 * stride;
        } else {
            // Handle last row if h is odd
            for (int j = 0; j < 8; j++) {
                dst[j] = ((((A * src[j] + B * src[j + 1] + C * src[stride + j] + D * src[stride + j + 1])) + 32) >> 6);
            }
            dst += stride;
            src += stride;
        }
    }
}
