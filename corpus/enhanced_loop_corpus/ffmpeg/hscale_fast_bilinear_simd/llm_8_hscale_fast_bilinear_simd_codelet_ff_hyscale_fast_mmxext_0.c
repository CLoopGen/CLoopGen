#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        int32_t temp = src[srcW - 1] * 128;
        dst[i] = (int16_t)temp;
        for (j = 0; j < 2; j++) {
            dst[i] += (int16_t)(src[srcW - 1] * 2);
        }
    }
}
