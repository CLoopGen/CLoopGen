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
for (i = 0; i < 8; ++i) {
    int idx[8];
    for (int j = 0; j < 8; ++j) idx[j] = i + j * 8;
    tmp10 = temp[idx[0]] + temp[idx[4]];
    tmp11 = temp[idx[0]] - temp[idx[4]];
    tmp13 = temp[idx[2]] + temp[idx[6]];
    tmp12 = ((int)((temp[idx[2]] - temp[idx[6]]) * (unsigned int)(92682)) >> 16) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    z13 = temp[idx[5]] + temp[idx[3]];
    z10 = temp[idx[5]] - temp[idx[3]];
    z11 = temp[idx[1]] + temp[idx[7]];
    z12 = temp[idx[1]] - temp[idx[7]];
    tmp7 = z11 + z13;
    tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
    z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
    tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
    tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    block[idx[0]] = (tmp0 + tmp7) >> 6;
    block[idx[7]] = (tmp0 - tmp7) >> 6;
    block[idx[1]] = (tmp1 + tmp6) >> 6;
    block[idx[6]] = (tmp1 - tmp6) >> 6;
    block[idx[2]] = (tmp2 + tmp5) >> 6;
    block[idx[5]] = (tmp2 - tmp5) >> 6;
    block[idx[4]] = (tmp3 + tmp4) >> 6;
    block[idx[3]] = (tmp3 - tmp4) >> 6;
}
}
