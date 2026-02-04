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
    for (i = 0; i < h; i++) {
        int offset;
        for (offset = 0; offset < 8; offset++) {
            uint8_t val = (A * src[offset] + E * src[step + offset] + bias) >> 6;
            dst[offset] = ((dst[offset] + val + 1) >> 1);
        }

        dst += stride;
        src += stride;
    }
}
