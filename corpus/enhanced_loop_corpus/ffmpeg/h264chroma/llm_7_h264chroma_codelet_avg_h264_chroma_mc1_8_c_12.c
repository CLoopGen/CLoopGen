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
    uint8_t prev_dst_val = 0;
    for (i = 0; i < h; i++) {
        int computed = (A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + 32) >> 6;
        dst[0] = ((prev_dst_val + computed + 1) >> 1);
        prev_dst_val = dst[0];
        dst += stride;
        src += stride;
    }
}
