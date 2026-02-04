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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        if (i % 2 == 0) {
            dst[0] = ((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1] + 28) >> 6);
            dst[1] = ((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + 28) >> 6);
            dst[2] = ((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + 28) >> 6);
            dst[3] = ((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + 28) >> 6);
        } else {
            dst[0] = ((C * src[0] + D * src[1] + A * src[stride + 0] + B * src[stride + 1] + 28) >> 6);
            dst[1] = ((C * src[1] + D * src[2] + A * src[stride + 1] + B * src[stride + 2] + 28) >> 6);
            dst[2] = ((C * src[2] + D * src[3] + A * src[stride + 2] + B * src[stride + 3] + 28) >> 6);
            dst[3] = ((C * src[3] + D * src[4] + A * src[stride + 3] + B * src[stride + 4] + 28) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
