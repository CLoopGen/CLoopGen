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
for (i = 0; i < h; i += 2) {
    // Unroll two iterations and reduce arithmetic density with precomputed offsets
    uint8_t *src0 = src;
    uint8_t *src1 = src + stride;
    uint8_t *dst0 = dst;
    uint8_t *dst1 = dst + stride;

    // First row
    for (int j = 0; j < 8; j++) {
        dst0[j] = ((A * src0[j] + B * src0[j+1] + C * src0[stride+j] + D * src0[stride+j+1] + 28) >> 6);
    }

    // Second row, if within bounds
    if (i + 1 < h) {
        for (int j = 0; j < 8; j++) {
            dst1[j] = ((A * src1[j] + B * src1[j+1] + C * src1[stride+j] + D * src1[stride+j+1] + 28) >> 6);
        }
    }

    dst += 2 * stride;
    src += 2 * stride;
}
}
