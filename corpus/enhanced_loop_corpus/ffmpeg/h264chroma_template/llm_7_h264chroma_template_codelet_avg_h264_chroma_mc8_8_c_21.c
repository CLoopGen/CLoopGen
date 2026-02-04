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
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        int val = A * src[offset] + B * src[offset + 1] + 
                  C * src[stride + offset] + D * src[stride + offset + 1];
        int result = ((val + 32) >> 6);
        dst[offset] = ((dst[offset] + result + 1) >> 1);
        offset++;
    }

    dst += stride;
    src += stride;
}
}
