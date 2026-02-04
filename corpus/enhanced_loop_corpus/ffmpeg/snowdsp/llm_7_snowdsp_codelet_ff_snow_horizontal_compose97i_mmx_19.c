#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern  int w_r;
extern int i;
extern IDWTELEM * dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_r - 7; i += 8) {
    IDWTELEM temp0 = dst[i] - (b[i] + b[i+2]);
    IDWTELEM temp1 = dst[i+1] - (b[i+1] + b[i+3]);
    IDWTELEM temp2 = dst[i+2] - (b[i+2] + b[i+4]);
    IDWTELEM temp3 = dst[i+3] - (b[i+3] + b[i+5]);
    IDWTELEM temp4 = dst[i+4] - (b[i+4] + b[i+6]);
    IDWTELEM temp5 = dst[i+5] - (b[i+5] + b[i+7]);
    IDWTELEM temp6 = dst[i+6];
    IDWTELEM temp7 = dst[i+7];

    dst[i]   = temp0;
    dst[i+1] = temp1;
    dst[i+2] = temp2;
    dst[i+3] = temp3;
    dst[i+4] = temp4;
    dst[i+5] = temp5;

    asm volatile ("movd %0, %%mm0\n\t"
                  "movd %1, %%mm1\n\t"
                  "packuswb %%mm1, %%mm0\n\t"
                  "movq %%mm0, %2\n\t"
                  : 
                  : "r" ((int32_t)temp6), "r" ((int32_t)temp7), "m" (dst[i+6])
                  : "memory", "mm0", "mm1");
}
}
