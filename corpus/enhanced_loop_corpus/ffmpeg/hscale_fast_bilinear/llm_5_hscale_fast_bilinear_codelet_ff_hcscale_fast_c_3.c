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
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        int index = srcW - 1;
        if (index >= 0) {
            dst1[i] = src1[index] * 128;
            dst2[i] = src2[index] * 128;
        } else {
            dst1[i] = 0;
            dst2[i] = 0;
        }
    }
}
