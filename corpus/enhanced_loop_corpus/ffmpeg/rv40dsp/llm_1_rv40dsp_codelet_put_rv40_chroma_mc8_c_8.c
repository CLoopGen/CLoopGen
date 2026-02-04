#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern int i;
extern int bias;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        for (int k = 0; k < 8; k++) {
            dst[k] = (((A * src[k] + E * src[step + k] + bias)) >> 6);
            dst[stride + k] = (((A * src[stride + k] + E * src[step + stride + k] + bias)) >> 6);
        }
        dst += 2 * stride;
        src += 2 * stride;
    } else {
        for (int k = 0; k < 8; k++) {
            dst[k] = (((A * src[k] + E * src[step + k] + bias)) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
}
