#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint8_t *d = dst;
    uint8_t *s = src;
    for (i = 0; i < h; i++) {
        int t0 = (-1 * s[-2] + -2 * s[-1] + 96 * s[0] + 42 * s[1] + -7 * s[2]) + 64;
        int t1 = (-1 * s[-1] + -2 * s[0] + 96 * s[1] + 42 * s[2] + -7 * s[3]) + 64;
        int t2 = (-1 * s[0]  + -2 * s[1] + 96 * s[2] + 42 * s[3] + -7 * s[4]) + 64;
        int t3 = (-1 * s[1]  + -2 * s[2] + 96 * s[3] + 42 * s[4] + -7 * s[5]) + 64;
        int t4 = (-1 * s[2]  + -2 * s[3] + 96 * s[4] + 42 * s[5] + -7 * s[6]) + 64;
        int t5 = (-1 * s[3]  + -2 * s[4] + 96 * s[5] + 42 * s[6] + -7 * s[7]) + 64;
        int t6 = (-1 * s[4]  + -2 * s[5] + 96 * s[6] + 42 * s[7] + -7 * s[8]) + 64;
        int t7 = (-1 * s[5]  + -2 * s[6] + 96 * s[7] + 42 * s[8] + -7 * s[9]) + 64;

        d[0] = cm[t0 >> 7];
        d[1] = cm[t1 >> 7];
        d[2] = cm[t2 >> 7];
        d[3] = cm[t3 >> 7];
        d[4] = cm[t4 >> 7];
        d[5] = cm[t5 >> 7];
        d[6] = cm[t6 >> 7];
        d[7] = cm[t7 >> 7];

        d += dstStride;
        s += srcStride;
    }
}
