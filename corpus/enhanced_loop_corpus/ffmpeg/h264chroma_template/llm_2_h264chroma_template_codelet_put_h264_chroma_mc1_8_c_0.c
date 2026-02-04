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
    ptrdiff_t idx = i * stride;
    dst[idx] = ((((A * src[idx] + B * src[idx + 1] + C * src[idx + stride] + D * src[idx + stride + 1])) + 32) >> 6);
}
}
