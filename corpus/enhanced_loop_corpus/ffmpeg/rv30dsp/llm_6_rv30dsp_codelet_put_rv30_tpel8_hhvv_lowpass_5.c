#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < h; j++) {
        uint8_t temp_val;
        for (i = 0; i < w; i++) {
            int index = i + srcStride * 1;
            temp_val = src[index] + src[index + 1];
            dst[i] = cm[(temp_val + src[i + srcStride * 2] + 64) >> 6];
        }
        src += srcStride;
        dst += dstStride;
    }
}
