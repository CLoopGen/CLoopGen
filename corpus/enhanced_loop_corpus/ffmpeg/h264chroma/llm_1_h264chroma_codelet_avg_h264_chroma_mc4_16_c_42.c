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
    for (i = 0; i < h; i++) {
        for (int k = 0; k < 2; k++) {
            dst[0 + k*2] = (((dst[0 + k*2]) + ((((A * src[0 + k*2] + B * src[1 + k*2] + C * src[stride + 0 + k*2] + D * src[stride + 1 + k*2])) + 32) >> 6) + 1) >> 1);
            dst[1 + k*2] = (((dst[1 + k*2]) + ((((A * src[1 + k*2] + B * src[2 + k*2] + C * src[stride + 1 + k*2] + D * src[stride + 2 + k*2])) + 32) >> 6) + 1) >> 1);
        }
        dst += stride;
        src += stride;
    }
}
