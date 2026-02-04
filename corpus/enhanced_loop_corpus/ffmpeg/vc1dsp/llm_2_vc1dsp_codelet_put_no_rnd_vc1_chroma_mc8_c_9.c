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
    // Variant 1: Consecutive memory access with unrolled inner loop and sequential src/dst indexing
    for (i = 0; i < h; i++) {
        ptrdiff_t base_src = i * stride;
        for (int j = 0; j < 8; j++) {
            ptrdiff_t idx = base_src + j;
            dst[j] = ((A * src[idx] + B * src[idx + 1] + C * src[idx + stride] + D * src[idx + stride + 1] + 28) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
