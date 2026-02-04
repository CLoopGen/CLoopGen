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
    for (i = 0; i < h * 2; i++) {
        int idx = i % 4;
        dst[idx] = (((A * src[idx]) + 32) >> 6);
        if ((i + 1) % 4 == 0) {
            dst += stride;
            src += stride;
        }
    }
}
