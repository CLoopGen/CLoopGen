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
for (i = 0; i < h; i += 2) {
    if (i + 1 < h) {
        dst[0] = ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1]) + 
                    A * src[stride*2+0] + B * src[stride*2+1] + C * src[stride*3+0] + D * src[stride*3+1]) + 64) >> 7);
        dst[1] = ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2]) + 
                    A * src[stride*2+1] + B * src[stride*2+2] + C * src[stride*3+1] + D * src[stride*3+2]) + 64) >> 7);
        dst += 2 * stride;
        src += 2 * stride;
    } else {
        dst[0] = ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6);
        dst[1] = ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6);
        dst += stride;
        src += stride;
    }
}
}
