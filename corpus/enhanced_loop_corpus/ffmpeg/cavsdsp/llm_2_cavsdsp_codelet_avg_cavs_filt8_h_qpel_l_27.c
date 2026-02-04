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
    for (i = 0; i < h; i++) {
        uint8_t *d = dst;
        const uint8_t *s = src;
        d[0] = ((d[0]) + cm[((-1 * s[-2] + -2 * s[-1] + 96 * s[0] + 42 * s[1] + -7 * s[2] + 0 * s[3]) + 64) >> 7] + 1) >> 1;
        d[1] = ((d[1]) + cm[((-1 * s[-1] + -2 * s[0] + 96 * s[1] + 42 * s[2] + -7 * s[3] + 0 * s[4]) + 64) >> 7] + 1) >> 1;
        d[2] = ((d[2]) + cm[((-1 * s[0] + -2 * s[1] + 96 * s[2] + 42 * s[3] + -7 * s[4] + 0 * s[5]) + 64) >> 7] + 1) >> 1;
        d[3] = ((d[3]) + cm[((-1 * s[1] + -2 * s[2] + 96 * s[3] + 42 * s[4] + -7 * s[5] + 0 * s[6]) + 64) >> 7] + 1) >> 1;
        d[4] = ((d[4]) + cm[((-1 * s[2] + -2 * s[3] + 96 * s[4] + 42 * s[5] + -7 * s[6] + 0 * s[7]) + 64) >> 7] + 1) >> 1;
        d[5] = ((d[5]) + cm[((-1 * s[3] + -2 * s[4] + 96 * s[5] + 42 * s[6] + -7 * s[7] + 0 * s[8]) + 64) >> 7] + 1) >> 1;
        d[6] = ((d[6]) + cm[((-1 * s[4] + -2 * s[5] + 96 * s[6] + 42 * s[7] + -7 * s[8] + 0 * s[9]) + 64) >> 7] + 1) >> 1;
        d[7] = ((d[7]) + cm[((-1 * s[5] + -2 * s[6] + 96 * s[7] + 42 * s[8] + -7 * s[9] + 0 * s[10]) + 64) >> 7] + 1) >> 1;
        dst += dstStride;
        src += srcStride;
    }
}
