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
        int index = srcW - 1;
        int16_t value = src[index];
        for (j = 0; j < 3; j++) {
            value = (value * 32) >> 7;
        }
        dst[i] = value;
    }
}
