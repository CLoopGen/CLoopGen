#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
    uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7];
    uint8_t temp8 = src[8], temp9 = src[9];

    dst[0] = cm[(9 * (temp0 + temp1) - (src[-1] + temp2) + 8) >> 4];
    dst[1] = cm[(9 * (temp1 + temp2) - (temp0 + temp3) + 8) >> 4];
    dst[2] = cm[(9 * (temp2 + temp3) - (temp1 + temp4) + 8) >> 4];
    dst[3] = cm[(9 * (temp3 + temp4) - (temp2 + temp5) + 8) >> 4];
    dst[4] = cm[(9 * (temp4 + temp5) - (temp3 + temp6) + 8) >> 4];
    dst[5] = cm[(9 * (temp5 + temp6) - (temp4 + temp7) + 8) >> 4];
    dst[6] = cm[(9 * (temp6 + temp7) - (temp5 + temp8) + 8) >> 4];
    dst[7] = cm[(9 * (temp7 + temp8) - (temp6 + temp9) + 8) >> 4];

    dst += dstStride;
    src += srcStride;
}
}
