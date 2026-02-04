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
    int skip = (src[0] == 0);
    if (!skip) {
        dst[0] = ((((A * src[0])) + 32) >> 6);
    }
    dst += stride;
    src += stride;
}
}
