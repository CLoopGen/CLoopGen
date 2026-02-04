#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_prev = dst - stride;
    for (i = 0; i < h; i++) {
        if (i > 0) {
            dst[0] = (((dst_prev[stride]) + ((((A * src[0])) + 32) >> 6) + 1) >> 1);
        } else {
            dst[0] = (((dst[0]) + ((((A * src[0])) + 32) >> 6) + 1) >> 1);
        }
        dst_prev = dst;
        dst += stride;
        src += stride;
    }
}
