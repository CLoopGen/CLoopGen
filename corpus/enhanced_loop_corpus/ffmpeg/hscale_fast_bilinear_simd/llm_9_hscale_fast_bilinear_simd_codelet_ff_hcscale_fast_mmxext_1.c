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
    int step = xInc >> 8;
    if (step == 0) step = 1;
    for (i = dstWidth - 1; i >= 0 && ((i * step) >> 16) >= (srcW >> 1); i -= 2) {
        int16_t base_val1 = src1[srcW - 1] * 128;
        int16_t base_val2 = src2[srcW - 1] * 128;
        dst1[i] = base_val1;
        dst2[i] = base_val2;
        if (i - 1 >= 0) {
            dst1[i - 1] = base_val1 ^ 0xFF;  
            dst2[i - 1] = base_val2 ^ 0xFF;
        }
    }
}
