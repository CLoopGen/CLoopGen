#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in chunks
    uint8_t *d = dst;
    uint8_t *s = src;
    ptrdiff_t s_stride = stride;
    for (i = 0; i < h; i++) {
        d[0] = ((d[0] + (((A * s[0] + B * s[1] + C * s[s_stride + 0] + D * s[s_stride + 1]) + 32) >> 6) + 1) >> 1);
        d[1] = ((d[1] + (((A * s[1] + B * s[2] + C * s[s_stride + 1] + D * s[s_stride + 2]) + 32) >> 6) + 1) >> 1);
        d[2] = ((d[2] + (((A * s[2] + B * s[3] + C * s[s_stride + 2] + D * s[s_stride + 3]) + 32) >> 6) + 1) >> 1);
        d[3] = ((d[3] + (((A * s[3] + B * s[4] + C * s[s_stride + 3] + D * s[s_stride + 4]) + 32) >> 6) + 1) >> 1);
        d += s_stride;
        s += s_stride;
    }
}
