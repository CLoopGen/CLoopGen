#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < h; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
            dst += stride;
            src += stride;
        }
    }
}
