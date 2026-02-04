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
    int step = (xInc >> 8) + 1;
    for (i = dstWidth - 1; i >= 0 && ((i * xInc) >> 16) >= (srcW >> 1); i -= step) {
        int index = (srcW >> 1);
        int16_t base_val1 = src1[index] * 128;
        int16_t base_val2 = src2[index] * 128;
        dst1[i] = base_val1;
        if (i > 0) {
            dst1[i-1] = base_val1;
        }
        dst2[i] = base_val2;
        if (i > 0) {
            dst2[i-1] = base_val2;
        }
    }
}
