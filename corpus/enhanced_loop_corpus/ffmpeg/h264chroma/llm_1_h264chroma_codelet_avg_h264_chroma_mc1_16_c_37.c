#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    for (int k = 0; k < 1; k++) {
        dst[0] = (((dst[0]) + ((((A * src[0] + E * src[step + 0])) + 32) >> 6) + 1) >> 1);
        dst += stride;
        src += stride;
    }
}
}
