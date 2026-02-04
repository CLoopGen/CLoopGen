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
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        int val1 = src[0];
        int val2 = src[step + 0];
        dst[0] = ((((A * val1 + E * val2)) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
