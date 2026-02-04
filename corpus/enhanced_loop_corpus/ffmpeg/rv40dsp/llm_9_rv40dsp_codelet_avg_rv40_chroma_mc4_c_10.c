#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern int i;
extern int bias;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h && i < 16; i++) {
    for (int j = 0; j < 8; j++) {
        int index = j;
        int temp = (A * src[index] + E * src[step + index] + bias) >> 6;
        dst[index] = ((dst[index] + temp + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
