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
    // Variant 1: Consecutive memory access with unrolled inner loop and linearized indexing
    ptrdiff_t s = stride;
    for (i = 0; i < h; i++) {
        ptrdiff_t base_src = i * s;
        ptrdiff_t base_dst = i * s;
        // Process 4 elements consecutively using flat indexing
        for (int j = 0; j < 4; j++) {
            int val = A * src[base_src + j] + B * src[base_src + j + 1] +
                      C * src[base_src + s + j] + D * src[base_src + s + j + 1];
            dst[base_dst + j] = ((dst[base_dst + j] + (((val + 32) >> 6) + 1)) >> 1);
        }
    }
}
