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
    uint8_t *d = dst;
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    uint8_t *s3 = src3;
    uint8_t *s4 = src4;
    for (y = 0; y < b_h; y++) {
        for (x = 0; x < b_w; x++) {
            int temp1 = (8 - dx) * (8 - dy) * s1[x];
            int temp2 = dx * (8 - dy) * s2[x];
            int temp3 = (8 - dx) * dy * s3[x];
            int temp4 = dx * dy * s4[x];
            d[x] = (temp1 + temp2 + temp3 + temp4 + 32) >> 6;
        }
        s1 += stride1;
        s2 += stride2;
        s3 += stride3;
        s4 += stride4;
        d += stride;
    }
}
