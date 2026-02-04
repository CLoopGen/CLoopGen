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
for (i = 0; i < h; i++) {
    ptrdiff_t base_src = i * stride;
    ptrdiff_t base_dst = i * stride;
    const int coeffs[4] = {A, B, C, D};
    for (int j = 0; j < 8; j++) {
        int val = coeffs[0] * src[base_src + j + 0] +
                  coeffs[1] * src[base_src + j + 1] +
                  coeffs[2] * src[base_src + j + stride] +
                  coeffs[3] * src[base_src + j + stride + 1];
        dst[base_dst + j] = ((val + 32) >> 6);
    }
}
}
