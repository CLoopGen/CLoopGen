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
    int val0 = A * src[0];
    int val1 = A * src[1];
    int val2 = A * src[2];
    int val3 = A * src[3];
    dst[0] = ((val0 + val1 + 64) >> 7);
    dst[1] = ((val2 + val3 + 64) >> 7);
    dst += stride;
    src += stride;
}
}
