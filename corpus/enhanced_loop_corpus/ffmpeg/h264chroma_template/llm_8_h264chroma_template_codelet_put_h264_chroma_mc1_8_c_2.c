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
    dst[0] = ((((A * src[0])) + 32) >> 6);
    if (i + 1 < h) {
        dst[stride] = ((((A * src[stride])) + 32) >> 6);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
