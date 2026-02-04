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
int limit = (h + 3) / 4;
for (i = 0; i < limit; i++) {
    dst[0] = ((((A * src[0])) + 32) >> 6);
    if (i*4+1 < h) {
        dst[stride] = ((((A * src[stride])) + 32) >> 6);
    }
    if (i*4+2 < h) {
        dst[2*stride] = ((((A * src[2*stride])) + 32) >> 6);
    }
    if (i*4+3 < h) {
        dst[3*stride] = ((((A * src[3*stride])) + 32) >> 6);
    }
    dst += 4 * stride;
    src += 4 * stride;
}
}
