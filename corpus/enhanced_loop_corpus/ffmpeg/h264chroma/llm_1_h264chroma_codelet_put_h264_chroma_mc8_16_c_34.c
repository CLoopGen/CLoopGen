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
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 8; j++) {
                dst[j] = ((((A * src[j] + E * src[step + j])) + 32) >> 6);
            }
            dst += stride;
            src += stride;
        }
    } else {
        for (int j = 0; j < 8; j++) {
            dst[j] = ((((A * src[j] + E * src[step + j])) + 32) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
}
