#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
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
extern int z5;
extern int z10;
extern int z11;
extern int z12;
extern int z13;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 * 8; i += 8) {
    tmp10 = temp[0 + i] + temp[4 + i];
    tmp11 = temp[0 + i] - temp[4 + i];
    tmp13 = temp[2 + i] + temp[6 + i];

    if (tmp13 == 0) continue;

    tmp12 = ((int)((temp[2 + i] - temp[6 + i]) * (unsigned int)(92682)) >> 16) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    z13 = temp[5 + i] + temp[3 + i];
    z10 = temp[5 + i] - temp[3 + i];
    z11 = temp[1 + i] + temp[7 + i];
    z12 = temp[1 + i] - temp[7 + i];

    if (z11 + z13 == 0) {
        tmp7 = 0;
        tmp11 = 0;
    } else {
        tmp7 = z11 + z13;
        tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
    }

    z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
    tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
    tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;

    block[0 + i] = (tmp0 + tmp7) >> 6;
    block[7 + i] = (tmp0 - tmp7) >> 6;
    block[1 + i] = (tmp1 + tmp6) >> 6;
    block[6 + i] = (tmp1 - tmp6) >> 6;
    block[2 + i] = (tmp2 + tmp5) >> 6;
    block[5 + i] = (tmp2 - tmp5) >> 6;
    block[4 + i] = (tmp3 + tmp4) >> 6;
    block[3 + i] = (tmp3 - tmp4) >> 6;
}
}
