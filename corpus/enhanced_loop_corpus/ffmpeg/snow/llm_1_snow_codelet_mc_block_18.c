#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int a;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < b_h; y += 2) {
    if (y + 1 < b_h) {
        for (x = 0; x < b_w; x++) {
            dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
        }
        src1 += stride1;
        src2 += stride2;
        dst += stride;
        for (x = 0; x < b_w; x++) {
            dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
        }
        src1 += stride1;
        src2 += stride2;
        dst += stride;
    } else {
        for (x = 0; x < b_w; x++) {
            dst[x] = (a * src1[x] + b * src2[x] + 4) >> 3;
        }
        src1 += stride1;
        src2 += stride2;
        dst += stride;
    }
}
}
