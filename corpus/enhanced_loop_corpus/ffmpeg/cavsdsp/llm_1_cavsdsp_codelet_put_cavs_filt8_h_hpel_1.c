#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i += 2) {
        if (i + 1 < h) {
            // Process two rows per iteration
            uint8_t *src1 = src;
            uint8_t *src2 = src + srcStride;
            uint8_t *dst1 = dst;
            uint8_t *dst2 = dst + dstStride;

            for (int j = 0; j < 8; j++) {
                dst1[j] = cm[((0 * src1[j-2] + -1 * src1[j-1] + 5 * src1[j] + 5 * src1[j+1] + -1 * src1[j+2] + 0 * src1[j+3]) + 4) >> 3];
                dst2[j] = cm[((0 * src2[j-2] + -1 * src2[j-1] + 5 * src2[j] + 5 * src2[j+1] + -1 * src2[j+2] + 0 * src2[j+3]) + 4) >> 3];
            }

            src += 2 * srcStride;
            dst += 2 * dstStride;
        } else {
            // Handle last row if h is odd
            for (int j = 0; j < 8; j++) {
                dst[0] = cm[((0 * src[-2] + -1 * src[-1] + 5 * src[0] + 5 * src[1] + -1 * src[2] + 0 * src[3]) + 4) >> 3];
                dst[1] = cm[((0 * src[-1] + -1 * src[0] + 5 * src[1] + 5 * src[2] + -1 * src[3] + 0 * src[4]) + 4) >> 3];
                dst[2] = cm[((0 * src[0] + -1 * src[1] + 5 * src[2] + 5 * src[3] + -1 * src[4] + 0 * src[5]) + 4) >> 3];
                dst[3] = cm[((0 * src[1] + -1 * src[2] + 5 * src[3] + 5 * src[4] + -1 * src[5] + 0 * src[6]) + 4) >> 3];
                dst[4] = cm[((0 * src[2] + -1 * src[3] + 5 * src[4] + 5 * src[5] + -1 * src[6] + 0 * src[7]) + 4) >> 3];
                dst[5] = cm[((0 * src[3] + -1 * src[4] + 5 * src[5] + 5 * src[6] + -1 * src[7] + 0 * src[8]) + 4) >> 3];
                dst[6] = cm[((0 * src[4] + -1 * src[5] + 5 * src[6] + 5 * src[7] + -1 * src[8] + 0 * src[9]) + 4) >> 3];
                dst[7] = cm[((0 * src[5] + -1 * src[6] + 5 * src[7] + 5 * src[8] + -1 * src[9] + 0 * src[10]) + 4) >> 3];
                break; // Only execute once
            }
            src += srcStride;
            dst += dstStride;
        }
    }
}
