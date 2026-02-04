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
int j;
for (i = 0; i < h; i++) {
    for (j = 0; j < 4; j++) {
        int offset = j;
        int coeff = (j == 0 || j == 3) ? A : E;
        int neighbor_offset = (j == 0 || j == 1) ? 0 : step;
        int src_val = src[neighbor_offset + offset];
        dst[j] = ((dst[j]) + (((coeff * src_val + E * src[step + offset]) + 32) >> 6) + 1) >> 1;
    }
    dst += stride;
    src += stride;
}
}
