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
if (h > 0) {
    for (int k = 0; k < 4; k++) {
        dst[k] = (((A * src[k] + E * src[step + k] + bias)) >> 6);
    }
    dst += stride;
    src += stride;
    for (i = 1; i < h; i++) {
        for (int j = 0; j < 4; j++) {
            dst[j] = (((A * src[j] + E * src[step + j] + bias)) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
}
