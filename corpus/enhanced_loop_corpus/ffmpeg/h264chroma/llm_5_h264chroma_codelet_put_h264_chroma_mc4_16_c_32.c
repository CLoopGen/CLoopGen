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
    int j;
    for (j = 0; j < 4; j++) {
        if ((src[j] & 1) == 0) {
            dst[j] = (((A * src[j]) + 32) >> 6);
        } else {
            dst[j] = ((A * src[j]) >> 6);
        }
    }
    dst += stride;
    src += stride;
}
}
