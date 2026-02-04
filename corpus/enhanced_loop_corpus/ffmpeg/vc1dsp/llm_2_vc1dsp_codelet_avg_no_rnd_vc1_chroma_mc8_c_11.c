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
for (i = 0; i < h; i++) {
    uint8_t *dst_base = &dst[0];
    const uint8_t *src_base = &src[0];
    for (int j = 0; j < 8; j++) {
        dst_base[j] = (((dst_base[j]) + (((A * src_base[j] + B * src_base[j + 1] + C * src_base[stride + j] + D * src_base[stride + j + 1] + 32 - 4) >> 6)) + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
