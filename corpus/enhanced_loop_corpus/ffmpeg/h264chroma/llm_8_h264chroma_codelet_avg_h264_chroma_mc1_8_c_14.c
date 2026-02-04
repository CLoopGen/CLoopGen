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
    int temp1 = ((A * src[0]) + 32) >> 6;
    int temp2 = ((A * src[stride]) + 32) >> 6;
    dst[0] = (((dst[0]) + temp1 + temp2 + 2) >> 2);
    if (i + 1 < h) {
        dst[stride] = (((dst[stride]) + temp2 + temp1 + 2) >> 2);
    }
    dst += stride;
    src += stride;
}
}
