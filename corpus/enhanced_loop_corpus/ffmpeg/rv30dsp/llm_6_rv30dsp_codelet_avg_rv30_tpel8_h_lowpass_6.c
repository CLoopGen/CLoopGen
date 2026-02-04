#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = cm[(-(src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + 8) >> 4];
    uint8_t temp1 = cm[(-(src[0] + src[3]) + src[1] * C1 + src[2] * C2 + 8) >> 4];
    uint8_t temp2 = cm[(-(src[1] + src[4]) + src[2] * C1 + src[3] * C2 + 8) >> 4];
    uint8_t temp3 = cm[(-(src[2] + src[5]) + src[3] * C1 + src[4] * C2 + 8) >> 4];
    uint8_t temp4 = cm[(-(src[3] + src[6]) + src[4] * C1 + src[5] * C2 + 8) >> 4];
    uint8_t temp5 = cm[(-(src[4] + src[7]) + src[5] * C1 + src[6] * C2 + 8) >> 4];
    uint8_t temp6 = cm[(-(src[5] + src[8]) + src[6] * C1 + src[7] * C2 + 8) >> 4];
    uint8_t temp7 = cm[(-(src[6] + src[9]) + src[7] * C1 + src[8] * C2 + 8) >> 4];

    dst[0] = ((dst[0] + temp0 + 1) >> 1);
    dst[1] = ((dst[1] + temp1 + 1) >> 1);
    dst[2] = ((dst[2] + temp2 + 1) >> 1);
    dst[3] = ((dst[3] + temp3 + 1) >> 1);
    dst[4] = ((dst[4] + temp4 + 1) >> 1);
    dst[5] = ((dst[5] + temp5 + 1) >> 1);
    dst[6] = ((dst[6] + temp6 + 1) >> 1);
    dst[7] = ((dst[7] + temp7 + 1) >> 1);

    dst += dstStride;
    src += srcStride;
}
}
