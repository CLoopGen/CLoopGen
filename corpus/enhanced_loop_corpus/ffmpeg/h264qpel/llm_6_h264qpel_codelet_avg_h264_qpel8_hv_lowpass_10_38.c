#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    int16_t t0, t1, t2, t3, t4, t5, t6, t7;
    uint16_t s[11];
    s[0] = src[-2]; s[1] = src[-1]; s[2] = src[0]; s[3] = src[1]; s[4] = src[2];
    s[5] = src[3]; s[6] = src[4]; s[7] = src[5]; s[8] = src[6]; s[9] = src[7];
    s[10] = src[8]; // Load early to remove RAW hazards in computation

    t0 = (s[2] + s[3]) * 20 - (s[1] + s[4]) * 5 + (s[0] + s[5]) + pad;
    t1 = (s[3] + s[4]) * 20 - (s[2] + s[5]) * 5 + (s[1] + s[6]) + pad;
    t2 = (s[4] + s[5]) * 20 - (s[3] + s[6]) * 5 + (s[2] + s[7]) + pad;
    t3 = (s[5] + s[6]) * 20 - (s[4] + s[7]) * 5 + (s[3] + s[8]) + pad;
    t4 = (s[6] + s[7]) * 20 - (s[5] + s[8]) * 5 + (s[4] + s[9]) + pad;
    t5 = (s[7] + s[8]) * 20 - (s[6] + s[9]) * 5 + (s[5] + s[10]) + pad;
    t6 = (s[8] + s[9]) * 20 - (s[7] + s[10]) * 5 + (s[6] + src[11]) + pad;
    t7 = (s[9] + src[10]) * 20 - (s[8] + src[11]) * 5 + (s[7] + src[12]) + pad;

    tmp[0] = t0;
    tmp[1] = t1;
    tmp[2] = t2;
    tmp[3] = t3;
    tmp[4] = t4;
    tmp[5] = t5;
    tmp[6] = t6;
    tmp[7] = t7;

    tmp += tmpStride;
    src += srcStride;
}
}
