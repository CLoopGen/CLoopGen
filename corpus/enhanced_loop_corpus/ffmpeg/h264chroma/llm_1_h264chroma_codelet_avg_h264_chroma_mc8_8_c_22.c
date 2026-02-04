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
    for (int k = 0; k < 2; k++) {
        for (int j = 0; j < 4; j++) {
            int idx = k * 4 + j;
            dst[idx] = (((dst[idx]) + ((((A * src[idx] + E * src[step + idx])) + 32) >> 6) + 1) >> 1);
        }
    }
    dst += stride;
    src += stride;
}
}
