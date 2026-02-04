#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
        uint8_t temp_step0 = src[step + 0], temp_step1 = src[step + 1], temp_step2 = src[step + 2], temp_step3 = src[step + 3];
        
        dst[0] = (((A * temp0 + E * temp_step0) + 32) >> 6);
        dst[1] = (((A * temp1 + E * temp_step1) + 32) >> 6);
        dst[2] = (((A * temp2 + E * temp_step2) + 32) >> 6);
        dst[3] = (((A * temp3 + E * temp_step3) + 32) >> 6);

        // Introduce artificial loop-carried dependency via reusing a computed value in next iteration
        A = (A + dst[0]) % 257;  // RAW and WAW on A across iterations (loop-carried)
        
        dst += stride;
        src += stride;
    }
}
