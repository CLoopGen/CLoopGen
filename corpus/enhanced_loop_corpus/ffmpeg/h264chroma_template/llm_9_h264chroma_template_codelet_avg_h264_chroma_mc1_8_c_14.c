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
        if (i + 1 < h) {
            dst[0] = (((dst[0]) + ((((A * src[0])) + 64) >> 6)) >> 1);
            dst[stride] = (((dst[stride]) + ((((A * src[stride])) + 64) >> 6)) >> 1);
            dst += 2 * stride;
            src += 2 * stride;
        } else {
            dst[0] = (((dst[0]) + ((((A * src[0])) + 32) >> 6) + 1) >> 1);
        }
    }
}
