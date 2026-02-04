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
    // Variant 1: Consecutive memory access with manual pointer advancement
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        const uint8_t *s = local_src;
        uint8_t *d = local_dst;

        d[0] = cm[((0 * s[-2] + -1 * s[-1] + 5 * s[0] + 5 * s[1] + -1 * s[2] + 0 * s[3]) + 4) >> 3];
        d[1] = cm[((0 * s[-1] + -1 * s[0] + 5 * s[1] + 5 * s[2] + -1 * s[3] + 0 * s[4]) + 4) >> 3];
        d[2] = cm[((0 * s[0] + -1 * s[1] + 5 * s[2] + 5 * s[3] + -1 * s[4] + 0 * s[5]) + 4) >> 3];
        d[3] = cm[((0 * s[1] + -1 * s[2] + 5 * s[3] + 5 * s[4] + -1 * s[5] + 0 * s[6]) + 4) >> 3];
        d[4] = cm[((0 * s[2] + -1 * s[3] + 5 * s[4] + 5 * s[5] + -1 * s[6] + 0 * s[7]) + 4) >> 3];
        d[5] = cm[((0 * s[3] + -1 * s[4] + 5 * s[5] + 5 * s[6] + -1 * s[7] + 0 * s[8]) + 4) >> 3];
        d[6] = cm[((0 * s[4] + -1 * s[5] + 5 * s[6] + 5 * s[7] + -1 * s[8] + 0 * s[9]) + 4) >> 3];
        d[7] = cm[((0 * s[5] + -1 * s[6] + 5 * s[7] + 5 * s[8] + -1 * s[9] + 0 * s[10]) + 4) >> 3];

        local_dst += dstStride;
        local_src += srcStride;
    }
}
