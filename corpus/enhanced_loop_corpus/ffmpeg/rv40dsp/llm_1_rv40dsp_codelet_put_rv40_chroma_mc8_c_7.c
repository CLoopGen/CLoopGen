#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < h; outer++) {
        int inner_iters[8] = {0,1,2,3,4,5,6,7};
        for (int k = 0; k < 8; k++) {
            int j = inner_iters[k];
            dst[j] = (((A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1] + bias)) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
