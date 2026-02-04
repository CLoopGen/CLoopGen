#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of processing one row at a time with strided access, process 4 consecutive pixels per iteration
    // and update pointers once per iteration. This improves spatial locality.

    uint8_t *d = dst;
    uint8_t *s = src;
    for (i = 0; i < h; i++) {
        d[0] = ((A * s[0] + B * s[1] + C * s[stride + 0] + D * s[stride + 1] + 28) >> 6);
        d[1] = ((A * s[1] + B * s[2] + C * s[stride + 1] + D * s[stride + 2] + 28) >> 6);
        d[2] = ((A * s[2] + B * s[3] + C * s[stride + 2] + D * s[stride + 3] + 28) >> 6);
        d[3] = ((A * s[3] + B * s[4] + C * s[stride + 3] + D * s[stride + 4] + 28) >> 6);
        d += stride;
        s += stride;
    }
}
