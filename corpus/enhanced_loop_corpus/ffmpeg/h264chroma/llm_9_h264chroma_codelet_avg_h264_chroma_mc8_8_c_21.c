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
    for (int j = 0; j < 8; j++) {
        int val = A * src[j] + B * src[j + 1] + C * src[stride + j] + D * src[stride + j + 1];
        int result = ((val + 32) >> 6);
        dst[j] = (dst[j] + result + 1) >> 1;
    }
    dst += stride;
    src += stride;

    if (i + 1 >= h) break;

    for (int j = 0; j < 8; j++) {
        int val = A * src[j] + B * src[j + 1] + C * src[stride + j] + D * src[stride + j + 1];
        int result = ((val + 32) >> 6);
        dst[j] = (dst[j] + result + 1) >> 1;
    }
    dst += stride;
    src += stride;
}
}
