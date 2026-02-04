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
for (i = 0; i < h; i++) {
    uint8_t temp0 = cm[((0 * src[-2] + -1 * src[-1] + 5 * src[0] + 5 * src[1] + -1 * src[2] + 0 * src[3]) + 4) >> 3];
    uint8_t temp1 = cm[((0 * src[-1] + -1 * src[0] + 5 * src[1] + 5 * src[2] + -1 * src[3] + 0 * src[4]) + 4) >> 3];
    uint8_t temp2 = cm[((0 * src[0] + -1 * src[1] + 5 * src[2] + 5 * src[3] + -1 * src[4] + 0 * src[5]) + 4) >> 3];
    uint8_t temp3 = cm[((0 * src[1] + -1 * src[2] + 5 * src[3] + 5 * src[4] + -1 * src[5] + 0 * src[6]) + 4) >> 3];
    uint8_t temp4 = cm[((0 * src[2] + -1 * src[3] + 5 * src[4] + 5 * src[5] + -1 * src[6] + 0 * src[7]) + 4) >> 3];
    uint8_t temp5 = cm[((0 * src[3] + -1 * src[4] + 5 * src[5] + 5 * src[6] + -1 * src[7] + 0 * src[8]) + 4) >> 3];
    uint8_t temp6 = cm[((0 * src[4] + -1 * src[5] + 5 * src[6] + 5 * src[7] + -1 * src[8] + 0 * src[9]) + 4) >> 3];
    uint8_t temp7 = cm[((0 * src[5] + -1 * src[6] + 5 * src[7] + 5 * src[8] + -1 * src[9] + 0 * src[10]) + 4) >> 3];

    dst[0] = ((dst[0]) + temp0 + 1) >> 1;
    dst[1] = ((dst[1]) + temp1 + 1) >> 1;
    dst[2] = ((dst[2]) + temp2 + 1) >> 1;
    dst[3] = ((dst[3]) + temp3 + 1) >> 1;
    dst[4] = ((dst[4]) + temp4 + 1) >> 1;
    dst[5] = ((dst[5]) + temp5 + 1) >> 1;
    dst[6] = ((dst[6]) + temp6 + 1) >> 1;
    dst[7] = ((dst[7]) + temp7 + 1) >> 1;

    dst += dstStride;
    src += srcStride;
}
}
