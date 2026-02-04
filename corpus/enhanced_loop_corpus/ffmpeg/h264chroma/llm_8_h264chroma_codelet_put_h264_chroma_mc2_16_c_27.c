#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    dst[0] = ((((A * src[0] + B * src[1]) + 32) >> 6));
    dst[1] = ((((A * src[1] + B * src[2]) + 32) >> 6));
    dst += stride;
    src += stride;
}
}
