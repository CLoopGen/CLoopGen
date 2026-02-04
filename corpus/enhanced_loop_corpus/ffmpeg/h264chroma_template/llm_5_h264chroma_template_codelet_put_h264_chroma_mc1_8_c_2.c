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
    int val = src[0];
    if (val > 16) {
        dst[0] = ((((A * val)) + 32) >> 6);
    }
    dst += stride;
    src += stride;
}
}
