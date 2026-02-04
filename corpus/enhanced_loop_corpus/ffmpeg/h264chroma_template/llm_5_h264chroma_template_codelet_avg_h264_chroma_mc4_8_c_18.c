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
    int index = (i & 1) ? 2 : 0;
    if (i < h / 2 || (i >= h / 2 && (dst[0] & 1))) {
        dst[index + 0] = (((dst[index + 0]) + ((((A * src[index + 0] + B * src[index + 1] + C * src[stride + index + 0] + D * src[stride + index + 1])) + 32) >> 6) + 1) >> 1);
        dst[index + 1] = (((dst[index + 1]) + ((((A * src[index + 1] + B * src[index + 2] + C * src[stride + index + 1] + D * src[stride + index + 2])) + 32) >> 6) + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
