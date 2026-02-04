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
    int i, j;
    for (i = 0; i < h; i++) {
        uint8_t temp_sum = 0;
        for (j = 0; j < 4; j++) {
            temp_sum += (A * src[j] + B * src[j+1] + C * src[stride + j] + D * src[stride + j+1]) >> 6;
        }
        dst[0] = (temp_sum + 2) >> 2; // Average of 4 computations, scaled
        dst += stride;
        src += stride;
    }
}
