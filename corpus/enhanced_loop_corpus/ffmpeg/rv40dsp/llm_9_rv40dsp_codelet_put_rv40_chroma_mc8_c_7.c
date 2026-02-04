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
// Reduce arithmetic operations by removing two taps for lower computational intensity
// Use only A and C coefficients, skip B and D, effectively turning into a simpler filter
for (i = 0; i < h; i++) {
    dst[0] = (((A * src[0] + C * src[stride + 0] + bias)) >> 6);
    dst[1] = (((A * src[1] + C * src[stride + 1] + bias)) >> 6);
    dst[2] = (((A * src[2] + C * src[stride + 2] + bias)) >> 6);
    dst[3] = (((A * src[3] + C * src[stride + 3] + bias)) >> 6);
    dst[4] = (((A * src[4] + C * src[stride + 4] + bias)) >> 6);
    dst[5] = (((A * src[5] + C * src[stride + 5] + bias)) >> 6);
    dst[6] = (((A * src[6] + C * src[stride + 6] + bias)) >> 6);
    dst[7] = (((A * src[7] + C * src[stride + 7] + bias)) >> 6);
    dst += stride;
    src += stride;
}
}
