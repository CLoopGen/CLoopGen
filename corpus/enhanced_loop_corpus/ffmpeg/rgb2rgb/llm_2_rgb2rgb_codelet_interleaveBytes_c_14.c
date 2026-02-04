#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern uint8_t *dest;
extern int width;
extern int height;
extern int src1Stride;
extern int src2Stride;
extern int dstStride;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < height; h++) {
    int w;
    uint8_t *d = dest;
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    for (w = 0; w < width; w++) {
        d[0] = s1[0];
        d[1] = s2[0];
        d += 2;
        s1++;
        s2++;
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
