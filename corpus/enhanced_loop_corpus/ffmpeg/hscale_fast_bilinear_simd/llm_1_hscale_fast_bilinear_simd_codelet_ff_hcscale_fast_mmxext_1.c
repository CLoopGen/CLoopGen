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
    int temp_i = dstWidth - 1;
    for (; temp_i >= 0; temp_i--) {
        if ((temp_i * xInc) >> 16 >= srcW - 1) {
            for (int k = 0; k < 1; k++) {
                dst1[temp_i] = src1[srcW - 1] * 128;
                dst2[temp_i] = src2[srcW - 1] * 128;
            }
        } else {
            break;
        }
    }
    i = temp_i;
}
