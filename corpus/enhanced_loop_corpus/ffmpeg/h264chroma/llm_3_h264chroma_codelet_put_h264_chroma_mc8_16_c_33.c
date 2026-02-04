#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t s0 = i * stride;
    ptrdiff_t s1 = s0 + stride;
    uint16_t temp_src[9];
    for (int j = 0; j < 9; j++) {
        temp_src[j] = src[s0 + j];
    }
    for (int j = 0; j < 9; j++) {
        temp_src[j + 9] = src[s1 + j]; // Store next row with offset
    }
    dst[0] = ((((A * temp_src[0] + B * temp_src[1] + C * temp_src[9 + 0] + D * temp_src[9 + 1])) + 32) >> 6);
    dst[1] = ((((A * temp_src[1] + B * temp_src[2] + C * temp_src[9 + 1] + D * temp_src[9 + 2])) + 32) >> 6);
    dst[2] = ((((A * temp_src[2] + B * temp_src[3] + C * temp_src[9 + 2] + D * temp_src[9 + 3])) + 32) >> 6);
    dst[3] = ((((A * temp_src[3] + B * temp_src[4] + C * temp_src[9 + 3] + D * temp_src[9 + 4])) + 32) >> 6);
    dst[4] = ((((A * temp_src[4] + B * temp_src[5] + C * temp_src[9 + 4] + D * temp_src[9 + 5])) + 32) >> 6);
    dst[5] = ((((A * temp_src[5] + B * temp_src[6] + C * temp_src[9 + 5] + D * temp_src[9 + 6])) + 32) >> 6);
    dst[6] = ((((A * temp_src[6] + B * temp_src[7] + C * temp_src[9 + 6] + D * temp_src[9 + 7])) + 32) >> 6);
    dst[7] = ((((A * temp_src[7] + B * temp_src[8] + C * temp_src[9 + 7] + D * temp_src[9 + 8])) + 32) >> 6);
    dst += stride;
    src += stride;
}
}
