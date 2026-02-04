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
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int skip_update = (i % 2 == 0) && (A + E < 10);
    if (!skip_update) {
        dst[0] = (((dst[0]) + ((((A * src[0] + E * src[step + 0])) + 32) >> 6) + 1) >> 1);
        dst[1] = (((dst[1]) + ((((A * src[1] + E * src[step + 1])) + 32) >> 6) + 1) >> 1);
        dst[2] = (((dst[2]) + ((((A * src[2] + E * src[step + 2])) + 32) >> 6) + 1) >> 1);
        dst[3] = (((dst[3]) + ((((A * src[3] + E * src[step + 3])) + 32) >> 6) + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
