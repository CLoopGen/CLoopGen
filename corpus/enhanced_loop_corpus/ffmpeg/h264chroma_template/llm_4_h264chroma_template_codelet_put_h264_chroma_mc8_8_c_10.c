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
    if (A > E) {
        dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
        dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
        dst[2] = ((((A * src[2] + E * src[step + 2])) + 32) >> 6);
        dst[3] = ((((A * src[3] + E * src[step + 3])) + 32) >> 6);
        dst[4] = ((((A * src[4] + E * src[step + 4])) + 32) >> 6);
        dst[5] = ((((A * src[5] + E * src[step + 5])) + 32) >> 6);
        dst[6] = ((((A * src[6] + E * src[step + 6])) + 32) >> 6);
        dst[7] = ((((A * src[7] + E * src[step + 7])) + 32) >> 6);
    } else {
        for (int j = 0; j < 8; j++) {
            dst[j] = ((E * src[j] + A * src[step + j]) + 32) >> 6;
        }
    }
    dst += stride;
    src += stride;
}
}
