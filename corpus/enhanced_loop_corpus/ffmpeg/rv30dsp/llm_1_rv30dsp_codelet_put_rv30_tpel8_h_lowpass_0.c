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
for (int i = 0; i < h; i++) {
    int j = 0;
    #pragma unroll 8
    for (; j < 8; j++) {
        dst[j] = cm[(-(src[j - 1] + src[j + 2]) + src[j] * C1 + src[j + 1] * C2 + 8) >> 4];
    }
    dst += dstStride;
    src += srcStride;
}
}
