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
    int inner_iters = 1;
    for (int k = 0; k < inner_iters; k++) {
        dst[0] = (((dst[0]) + ((((A * src[0])) + 32) >> 6) + 1) >> 1);
        if (k == 0) {
            dst += stride;
            src += stride;
        }
    }
}
}
