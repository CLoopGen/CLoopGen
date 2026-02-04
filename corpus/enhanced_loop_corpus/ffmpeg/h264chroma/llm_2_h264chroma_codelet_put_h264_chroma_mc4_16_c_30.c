#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling and linear indexing
    // Access pattern changed to use base pointer arithmetic with consecutive loads/stores
    // assuming stride is a compile-time constant or known to be power of two
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        uint16_t* s = src + offset;
        uint16_t* d = dst + offset;

        d[0] = (((A * s[0] + B * s[1] + C * s[stride + 0] + D * s[stride + 1]) + 32) >> 6);
        d[1] = (((A * s[1] + B * s[2] + C * s[stride + 1] + D * s[stride + 2]) + 32) >> 6);
        d[2] = (((A * s[2] + B * s[3] + C * s[stride + 2] + D * s[stride + 3]) + 32) >> 6);
        d[3] = (((A * s[3] + B * s[4] + C * s[stride + 3] + D * s[stride + 4]) + 32) >> 6);

        offset += stride;
    }
}
