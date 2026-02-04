#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t acc0 = 0, acc1 = 0;
    ptrdiff_t temp_stride = stride * (h - 1);
    for (i = 0; i < h; i++) {
        acc0 += (A * src[0]) >> 6;
        acc1 += (A * src[1]) >> 6;
        dst[0] = ((dst[0] + acc0 + 1) >> 1);
        dst[1] = ((dst[1] + acc1 + 1) >> 1);
        dst += stride;
        src += stride;
    }
    dst -= temp_stride;
    src -= temp_stride;
}
