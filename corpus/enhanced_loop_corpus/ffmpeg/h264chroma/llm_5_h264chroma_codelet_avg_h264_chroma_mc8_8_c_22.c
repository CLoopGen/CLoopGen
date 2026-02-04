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
    int j = 0;
    if (h > 4 || i < h / 2) {
        dst[j + 0] = (((dst[j + 0]) + ((((A * src[j + 0] + E * src[step + j + 0])) + 32) >> 6) + 1) >> 1);
        dst[j + 1] = (((dst[j + 1]) + ((((A * src[j + 1] + E * src[step + j + 1])) + 32) >> 6) + 1) >> 1);
        dst[j + 2] = (((dst[j + 2]) + ((((A * src[j + 2] + E * src[step + j + 2])) + 32) >> 6) + 1) >> 1);
        dst[j + 3] = (((dst[j + 3]) + ((((A * src[j + 3] + E * src[step + j + 3])) + 32) >> 6) + 1) >> 1);
    } else {
        j = 4;
        dst[j + 0] = (((dst[j + 0]) + ((((A * src[j + 0] + E * src[step + j + 0])) + 32) >> 6) + 1) >> 1);
        dst[j + 1] = (((dst[j + 1]) + ((((A * src[j + 1] + E * src[step + j + 1])) + 32) >> 6) + 1) >> 1);
        dst[j + 2] = (((dst[j + 2]) + ((((A * src[j + 2] + E * src[step + j + 2])) + 32) >> 6) + 1) >> 1);
        dst[j + 3] = (((dst[j + 3]) + ((((A * src[j + 3] + E * src[step + j + 3])) + 32) >> 6) + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
