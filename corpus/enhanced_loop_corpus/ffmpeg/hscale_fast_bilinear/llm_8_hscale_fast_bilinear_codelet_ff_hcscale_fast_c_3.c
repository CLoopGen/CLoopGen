#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst1;
extern int16_t *dst2;
extern int dstWidth;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        int16_t val1 = src1[srcW - 1] * 128;
        int16_t val2 = src2[srcW - 1] * 128;
        dst1[i] = val1 + 16;
        dst2[i] = val2 - 16;
        for (j = 0; j < 3; j++) {
            dst1[i] += (val1 >> (j + 2));
            dst2[i] -= (val2 >> (j + 3));
        }
    }
}
