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
for (i = 0; i < h; i += 2) {
    int limit = (i + 1 < h) ? 2 : 1;
    for (int k = 0; k < limit; k++) {
        dst[0] = (((A * src[0]) + 32) >> 6);
        dst[1] = (((A * src[1]) + 32) >> 6);
        dst[2] = (((A * src[2]) + 32) >> 6);
        dst[3] = (((A * src[3]) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
