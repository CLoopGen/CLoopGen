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
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst[stride] = ((((A * (src[stride + 0]) + E * src[stride + step + 0])) + 32) >> 6);
        dst[stride + 1] = ((((A * (src[stride + 1]) + E * src[stride + step + 1])) + 32) >> 6);
        dst += 2 * stride;
        src += 2 * stride;
    } else {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
