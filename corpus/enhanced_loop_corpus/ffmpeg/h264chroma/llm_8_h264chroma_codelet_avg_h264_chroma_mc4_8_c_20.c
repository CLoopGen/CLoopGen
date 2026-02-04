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
    int temp0 = (A * src[0]) + 32;
    int temp1 = (A * src[1]) + 32;
    int temp2 = (A * src[2]) + 32;
    int temp3 = (A * src[3]) + 32;
    dst[0] = ((dst[0] + (temp0 >> 6) + 1) >> 1);
    dst[1] = ((dst[1] + (temp1 >> 6) + 1) >> 1);
    dst[2] = ((dst[2] + (temp2 >> 6) + 1) >> 1);
    dst[3] = ((dst[3] + (temp3 >> 6) + 1) >> 1);
    dst += stride;
    src += stride;
}
}
