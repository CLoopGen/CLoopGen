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
    if (h > 0) {
        i = 0;
        do {
            dst[0] = (((dst[0]) + ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6) + 1) >> 1);
            dst[1] = (((dst[1]) + ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6) + 1) >> 1);
            dst += stride;
            src += stride;
            i++;
        } while (i < h);
    }
}
