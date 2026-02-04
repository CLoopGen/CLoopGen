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
        dst[0] = (((A * src[0] + A * src[1]) >> 1) + 32) >> 6;
        dst[1] = (((A * src[1] + A * src[2]) >> 1) + 32) >> 6;
        dst[2] = (((A * src[2] + A * src[3]) >> 1) + 32) >> 6;
        dst[3] = (((A * src[3] + A * src[0]) >> 1) + 32) >> 6;
        dst += stride;
        src += stride;
    }
}
