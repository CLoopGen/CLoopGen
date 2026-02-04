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
    uint16_t acc = 0;
    for (i = 0; i < h; i++) {
        acc += A; // Introduce loop-carried dependency (WAW on acc)
        dst[0] = (((acc * src[0]) + 32) >> 6);
        dst[1] = (((acc * src[1]) + 32) >> 6);
        dst[2] = (((acc * src[2]) + 32) >> 6);
        dst[3] = (((acc * src[3]) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
