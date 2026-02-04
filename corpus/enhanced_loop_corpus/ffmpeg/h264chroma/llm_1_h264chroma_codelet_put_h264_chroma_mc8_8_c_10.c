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
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int j = 0;
    for (; j < 4; j++) {
        dst[j] = ((((A * src[j] + E * src[step + j])) + 32) >> 6);
    }
    for (; j < 8; j++) {
        dst[j] = ((((A * src[j] + E * src[step + j])) + 32) >> 6);
    }
    dst += stride;
    src += stride;
}
}
