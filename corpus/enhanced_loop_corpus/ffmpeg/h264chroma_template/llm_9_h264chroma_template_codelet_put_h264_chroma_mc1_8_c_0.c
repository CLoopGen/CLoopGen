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
    int val1 = A * src[0];
    int val2 = B * src[1];
    int val3 = C * src[stride + 0];
    int val4 = D * src[stride + 1];
    int sum = val1 + val2 + val3 + val4;
    int offset_sum = sum + 32;
    dst[0] = offset_sum >> 6;
    dst += stride;
    src += stride;
}
}
