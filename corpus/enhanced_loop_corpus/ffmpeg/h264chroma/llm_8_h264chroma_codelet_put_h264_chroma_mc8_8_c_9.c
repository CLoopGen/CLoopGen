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
for (i = 0; i < h; i++) {
    dst[0] = ((A * src[0] + B * src[1] + C * src[stride] + D * src[stride + 1] + 16) >> 5);
    dst[1] = ((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2] + 16) >> 5);
    dst[2] = ((A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3] + 16) >> 5);
    dst[3] = ((A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4] + 16) >> 5);
    dst += stride;
    src += stride;
}
}
