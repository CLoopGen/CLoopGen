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
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        ptrdiff_t idx = offset + j;
        ptrdiff_t stride_idx = stride + idx;
        int sum = A * src[idx] + B * src[idx + 1] + C * src[stride_idx] + D * src[stride_idx + 1];
        int result = (sum + 28) >> 6;
        dst[idx] = ((dst[idx] + result + 1) >> 1);
    }
    dst += stride;
    src += stride;
}
}
