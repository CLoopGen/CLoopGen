#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int stride;
extern int h;
extern int rounder;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    // Unroll two iterations and reduce arithmetic density by reusing common terms
    uint8_t *src1 = src;
    uint8_t *src2 = src + stride;
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + stride;

    for (int j = 0; j < 8; j++) {
        int temp1 = A * src1[j] + B * src1[j+1] + C * src2[j] + D * src2[j+1] + rounder;
        dst1[j] = temp1 >> 8;
    }

    if (i + 1 < h) {
        src1 = src + stride;
        src2 = src + 2 * stride;
        dst1 = dst + stride;
        dst2 = dst + 2 * stride;

        for (int j = 0; j < 8; j++) {
            int temp1 = A * src1[j] + B * src1[j+1] + C * src2[j] + D * src2[j+1] + rounder;
            dst1[j] = temp1 >> 8;
        }
    }

    dst += 2 * stride;
    src += 2 * stride;
}
}
