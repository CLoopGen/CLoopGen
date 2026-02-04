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
    uint8_t temp_src[10];
    uint8_t temp_dst[8];
    
    int k;
    for (k = 0; k < 10; k++) {
        temp_src[k] = src[k - 1];
    }
    for (k = 0; k < 8; k++) {
        temp_dst[k] = dst[k];
    }
    
    for (k = 0; k < 8; k++) {
        int val = (-(temp_src[k+0] + temp_src[k+3]) + temp_src[k+1] * C1 + temp_src[k+2] * C2 + 8) >> 4;
        temp_dst[k] = ((temp_dst[k] + cm[val] + 1) >> 1);
    }
    
    for (k = 0; k < 8; k++) {
        dst[k] = temp_dst[k];
    }

    dst += dstStride;
    src += srcStride;
}
}
