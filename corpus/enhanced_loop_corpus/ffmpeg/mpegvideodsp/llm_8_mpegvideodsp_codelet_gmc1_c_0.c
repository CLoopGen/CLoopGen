#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int stride;
extern int h;
extern int rounder;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    for (int j = 0; j < 8; j++) {
        dst[j] = (A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j + 1] + rounder) >> 8;
    }
    dst += stride;
    src += stride;
}
}
