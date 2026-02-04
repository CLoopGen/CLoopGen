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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        for (int k = 0; k < 2; k++) {
            dst[k] = (((dst[k]) + (((A * src[k]) + 32) >> 6) + 1) >> 1);
        }
        dst += stride;
        src += stride;
    }
}
