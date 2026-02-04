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
        int j;
        for (j = 0; j < 8; j++) {
            int val = (A * src[j] + E * src[step + j]);
            int shifted_val = (val + 32) >> 6;
            dst[j] = ((dst[j] + shifted_val + 1) >> 1);
        }

        dst += stride;
        src += stride;
    }
}
