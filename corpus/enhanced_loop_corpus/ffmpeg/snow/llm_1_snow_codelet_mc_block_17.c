#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int dx;
extern int dy;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern  uint8_t *src4;
extern int stride1;
extern int stride2;
extern int stride3;
extern int stride4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y++) {
    x = 0;
    for (; x < b_w; ) {
        dst[x] = ((8 - dx) * (8 - dy) * src1[x] + dx * (8 - dy) * src2[x] + (8 - dx) * dy * src3[x] + dx * dy * src4[x] + 32) >> 6;
        x++;
    }
    src1 += stride1;
    src2 += stride2;
    src3 += stride3;
    src4 += stride4;
    dst += stride;
}
}
