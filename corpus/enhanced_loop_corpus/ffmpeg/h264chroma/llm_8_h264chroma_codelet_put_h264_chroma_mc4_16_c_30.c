#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < 4; j++) {
            dst[j] = ((((A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1])) + 32) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
