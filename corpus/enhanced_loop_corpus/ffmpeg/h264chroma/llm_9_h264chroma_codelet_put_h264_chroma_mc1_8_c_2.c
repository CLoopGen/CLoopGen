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
for (i = 0; i < h * 2; i++) {
    int offset = (i % 2) * 4;
    dst[offset] = ((((A * src[offset]) + 16) >> 5));
    dst += stride / 2;
    src += stride / 2;
}
}
