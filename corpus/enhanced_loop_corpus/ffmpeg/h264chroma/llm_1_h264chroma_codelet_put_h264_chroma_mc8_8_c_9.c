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
    int offset = i * stride;
    for (int k = 0; k < 8; k++) {
        int s_index = offset + k;
        dst[s_index] = ((((A * src[s_index] + B * src[s_index + 1] 
                         + C * src[s_index + stride] + D * src[s_index + stride + 1]) + 32) >> 6));
    }
}
}
