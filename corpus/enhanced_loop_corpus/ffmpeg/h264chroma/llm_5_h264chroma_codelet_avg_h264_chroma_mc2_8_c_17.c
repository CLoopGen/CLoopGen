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
        int index = (i & 1) ? 1 : 0;
        dst[index] = (((dst[index]) + (((A * src[index]) + 32) >> 6) + 1) >> 1);
        if (i % 2 == 0) {
            dst += stride;
            src += stride;
        }
    }
}
