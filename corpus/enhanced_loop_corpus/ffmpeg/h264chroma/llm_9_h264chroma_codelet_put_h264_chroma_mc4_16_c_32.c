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
for (i = 0; i < h; i += 2) {
    int j;
    for (j = 0; j < 4; j++) {
        dst[j] = (((A * src[j]) + 32) >> 6);
    }
    dst += stride;
    src += stride;
    if (i + 1 < h) {
        for (j = 0; j < 4; j++) {
            dst[j] = (((A * src[j]) + 32) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
}
