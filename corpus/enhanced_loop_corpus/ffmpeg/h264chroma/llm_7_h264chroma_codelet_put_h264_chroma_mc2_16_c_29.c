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
    uint16_t acc[2] = {0};
    for (i = 0; i < h; i++) {
        acc[0] = (((A * src[0]) + 32) >> 6);
        acc[1] = (((A * src[1]) + 32) >> 6);
        dst[0] = acc[0];
        dst[1] = acc[1];
        dst += stride;
        src += stride;
    }
}
