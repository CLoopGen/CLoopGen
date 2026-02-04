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
for (int outer = 0; outer < h; outer++) {
    for (int inner = 0; inner < 1; inner++) {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
