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
    ptrdiff_t s = stride;
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3], temp4 = src[4];
        uint8_t temp_s0 = src[s + 0], temp_s1 = src[s + 1], temp_s2 = src[s + 2], temp_s3 = src[s + 3], temp_s4 = src[s + 4];

        dst[0] = (((A * temp0 + B * temp1 + C * temp_s0 + D * temp_s1) + 32) >> 6);
        dst[1] = (((A * temp1 + B * temp2 + C * temp_s1 + D * temp_s2) + 32) >> 6);
        dst[2] = (((A * temp2 + B * temp3 + C * temp_s2 + D * temp_s3) + 32) >> 6);
        dst[3] = (((A * temp3 + B * temp4 + C * temp_s3 + D * temp_s4) + 32) >> 6);

        dst += s;
        src += s;
    }
}
