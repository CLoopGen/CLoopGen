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
    // Variant 2: Strided memory access with transposed computation order (column-wise processing)
    ptrdiff_t s = stride;
    // Process each column separately across all rows, then advance
    for (int col = 0; col < 4; col++) {
        uint8_t* d = &dst[col];
        uint8_t* s0 = &src[col];
        uint8_t* s1 = &src[s + col];
        for (i = 0; i < h; i++) {
            int val = A * s0[0] + B * s0[1] + C * s1[0] + D * s1[1];
            d[0] = ((d[0] + (((val + 32) >> 6) + 1)) >> 1);
            d += s;
            s0 += s;
            s1 += s;
        }
    }
}
