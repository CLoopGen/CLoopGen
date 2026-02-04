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
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
    uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7];
    uint8_t temp_step0 = src[step + 0], temp_step1 = src[step + 1];
    uint8_t temp_step2 = src[step + 2], temp_step3 = src[step + 3];
    uint8_t temp_step4 = src[step + 4], temp_step5 = src[step + 5];
    uint8_t temp_step6 = src[step + 6], temp_step7 = src[step + 7];

    dst[0] = ((((A * temp0 + E * temp_step0)) + 32) >> 6);
    dst[1] = ((((A * temp1 + E * temp_step1)) + 32) >> 6);
    dst[2] = ((((A * temp2 + E * temp_step2)) + 32) >> 6);
    dst[3] = ((((A * temp3 + E * temp_step3)) + 32) >> 6);
    dst[4] = ((((A * temp4 + E * temp_step4)) + 32) >> 6);
    dst[5] = ((((A * temp5 + E * temp_step5)) + 32) >> 6);
    dst[6] = ((((A * temp6 + E * temp_step6)) + 32) >> 6);
    dst[7] = ((((A * temp7 + E * temp_step7)) + 32) >> 6);

    dst += stride;
    src += stride;
}
}
