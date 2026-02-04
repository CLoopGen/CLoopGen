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
for (i = 0; i < h && i < 16; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
        sum += A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1];
    }
    int avg = (sum + 4 * bias) >> 8;
    dst[0] = ((dst[0] + avg + 1) >> 1);
    dst[1] = ((dst[1] + avg + 1) >> 1);
    dst[2] = ((dst[2] + avg + 1) >> 1);
    dst[3] = ((dst[3] + avg + 1) >> 1);

    dst += stride;
    src += stride;
}
}
