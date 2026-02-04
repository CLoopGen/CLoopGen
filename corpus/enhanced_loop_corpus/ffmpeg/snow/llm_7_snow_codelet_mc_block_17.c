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
    int offset = 0;
    for (y = 0; y < b_h; y++) {
        int acc = 32; // Initialize accumulator with rounding constant
        for (x = 0; x < b_w; x++) {
            acc += (8 - dx) * (8 - dy) * s1[x];
            acc += dx * (8 - dy) * s2[x];
            acc += (8 - dx) * dy * s3[x];
            acc += dx * dy * s4[x];
            d[x] = acc >> 6;
            acc -= (acc & ~63); // Reset accumulator to next byte's base (simulates reuse, introduces intra-loop dependency)
        }
        s1 += stride1;
        s2 += stride2;
        s3 += stride3;
        s4 += stride4;
        d += stride;
    }
}
