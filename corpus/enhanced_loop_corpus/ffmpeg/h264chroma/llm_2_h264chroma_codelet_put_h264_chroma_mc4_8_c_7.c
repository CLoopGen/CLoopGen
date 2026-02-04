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
    int k;
    for (k = 0; k < 4; k++) {
        dst[k] = ((((A * src[k] + E * src[step + k])) + 32) >> 6);
    }
    dst += stride;
    src += stride;
}
}
