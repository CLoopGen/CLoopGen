#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp0;
extern int tmp1;
extern int tmp2;
extern int tmp3;
extern int tmp4;
extern int tmp5;
extern int tmp6;
extern int tmp7;
extern int tmp10;
extern int tmp11;
extern int tmp12;
extern int tmp13;
extern int z1;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int16_t *base = dataptr;
        tmp0 = base[0] + base[8];
        tmp1 = base[16] + base[24];
        tmp2 = base[32] + base[40];
        tmp3 = base[48] + base[56];
        tmp4 = base[0] - base[8];
        tmp5 = base[16] - base[24];
        tmp6 = base[32] - base[40];
        tmp7 = base[48] - base[56];
        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;
        base[0] = tmp10 + tmp11;
        base[32] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * ((int32_t)181)) >> 8));
        base[16] = tmp13 + z1;
        base[48] = tmp13 - z1;
        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;
        base[8] = tmp10 + tmp11;
        base[40] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * ((int32_t)181)) >> 8));
        base[24] = tmp13 + z1;
        base[56] = tmp13 - z1;
        dataptr += 1;
    }
}
