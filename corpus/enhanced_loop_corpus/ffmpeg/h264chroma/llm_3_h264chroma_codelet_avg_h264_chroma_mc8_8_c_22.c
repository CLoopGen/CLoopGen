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
    dst[0*stride] = (((dst[0*stride]) + ((((A * src[0*stride] + E * src[step + 0*stride])) + 32) >> 6) + 1) >> 1);
    dst[1*stride] = (((dst[1*stride]) + ((((A * src[1*stride] + E * src[step + 1*stride])) + 32) >> 6) + 1) >> 1);
    dst[2*stride] = (((dst[2*stride]) + ((((A * src[2*stride] + E * src[step + 2*stride])) + 32) >> 6) + 1) >> 1);
    dst[3*stride] = (((dst[3*stride]) + ((((A * src[3*stride] + E * src[step + 3*stride])) + 32) >> 6) + 1) >> 1);
    dst[4*stride] = (((dst[4*stride]) + ((((A * src[4*stride] + E * src[step + 4*stride])) + 32) >> 6) + 1) >> 1);
    dst[5*stride] = (((dst[5*stride]) + ((((A * src[5*stride] + E * src[step + 5*stride])) + 32) >> 6) + 1) >> 1);
    dst[6*stride] = (((dst[6*stride]) + ((((A * src[6*stride] + E * src[step + 6*stride])) + 32) >> 6) + 1) >> 1);
    dst[7*stride] = (((dst[7*stride]) + ((((A * src[7*stride] + E * src[step + 7*stride])) + 32) >> 6) + 1) >> 1);
    dst += stride;
    src += stride;
}
}
