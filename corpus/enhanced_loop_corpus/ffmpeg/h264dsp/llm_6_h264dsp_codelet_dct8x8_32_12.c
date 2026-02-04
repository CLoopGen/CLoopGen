#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int32_t *base_tmp = tmp + 8 * i;
    int32_t *base_coef = coef + i;
    const int t0 = base_tmp[0], t1 = base_tmp[1], t2 = base_tmp[2], t3 = base_tmp[3];
    const int t4 = base_tmp[4], t5 = base_tmp[5], t6 = base_tmp[6], t7 = base_tmp[7];

    const int a0 = t0 + t7;
    const int a1 = t0 - t7;
    const int a2 = t1 + t6;
    const int a3 = t1 - t6;
    const int a4 = t2 + t5;
    const int a5 = t2 - t5;
    const int a6 = t3 + t4;
    const int a7 = t3 - t4;

    const int b0 = a0 + a6;
    const int b1 = a2 + a4;
    const int b2 = a0 - a6;
    const int b3 = a2 - a4;

    const int temp1 = a1 >> 1;
    const int temp2 = a5 >> 1;
    const int temp3 = a3 >> 1;
    const int temp4 = a7 >> 1;

    const int b4 = a3 + a5 + (a1 + temp1);
    const int b5 = a1 - a7 - (a5 + temp2);
    const int b6 = a1 + a7 - (a3 + temp3);
    const int b7 = a3 - a5 + (a7 + temp4);

    base_coef[0] = b0 + b1;
    base_coef[8] = b4 + (b7 >> 2);
    base_coef[16] = b2 + (b3 >> 1);
    base_coef[24] = b5 + (b6 >> 2);
    base_coef[32] = b0 - b1;
    base_coef[40] = b6 - (b5 >> 2);
    base_coef[48] = (b2 >> 1) - b3;
    base_coef[56] = (b4 >> 2) - b7;
}
}
