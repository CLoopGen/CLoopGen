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
    uint16_t s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    uint16_t s4 = src[4], s5 = src[5], s6 = src[6], s7 = src[7];
    uint16_t s8 = src[8], s9 = src[9], s10 = src[10];
    uint16_t s_1 = src[-1], s_2 = src[-2];

    t0 = (s0 + s1) * 20 - (s_1 + s2) * 5 + (src[-2] + s3) + pad;
    t1 = (s1 + s2) * 20 - (s0 + s3) * 5 + (s_1 + s4) + pad;
    t2 = (s2 + s3) * 20 - (s1 + s4) * 5 + (s0 + s5) + pad;
    t3 = (s3 + s4) * 20 - (s2 + s5) * 5 + (s1 + s6) + pad;
    t4 = (s4 + s5) * 20 - (s3 + s6) * 5 + (s2 + s7) + pad;
    t5 = (s5 + s6) * 20 - (s4 + s7) * 5 + (s3 + s8) + pad;
    t6 = (s6 + s7) * 20 - (s5 + s8) * 5 + (s4 + s9) + pad;
    t7 = (s7 + s8) * 20 - (s6 + s9) * 5 + (s5 + s10) + pad;

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
