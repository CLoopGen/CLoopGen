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
    for (i = 0; i < h; i++) {
        int factor = (A < 16) ? 16 : A;
        dst[0] = (((factor * src[0]) + 32) >> 6);
        dst[1] = (((factor * src[1]) + 32) >> 6);
        dst[2] = (((factor * src[2]) + 32) >> 6);
        dst[3] = (((factor * src[3]) + 32) >> 6);
        dst[4] = (((factor * src[4]) + 32) >> 6);
        dst[5] = (((factor * src[5]) + 32) >> 6);
        dst[6] = (((factor * src[6]) + 32) >> 6);
        dst[7] = (((factor * src[7]) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
