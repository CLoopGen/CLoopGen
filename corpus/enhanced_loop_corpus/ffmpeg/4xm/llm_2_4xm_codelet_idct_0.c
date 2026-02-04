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
for (i = 0; i < 8; i++) {
    int idx = i;
    tmp10 = block[idx] + block[32 + idx];
    tmp11 = block[idx] - block[32 + idx];
    tmp13 = block[16 + idx] + block[48 + idx];
    tmp12 = ((int)((block[16 + idx] - block[48 + idx]) * (unsigned int)(92682)) >> 16) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    z13 = block[40 + idx] + block[24 + idx];
    z10 = block[40 + idx] - block[24 + idx];
    z11 = block[8 + idx] + block[56 + idx];
    z12 = block[8 + idx] - block[56 + idx];
    tmp7 = z11 + z13;
    tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
    z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
    tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
    tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    temp[idx] = tmp0 + tmp7;
    temp[56 + idx] = tmp0 - tmp7;
    temp[8 + idx] = tmp1 + tmp6;
    temp[48 + idx] = tmp1 - tmp6;
    temp[16 + idx] = tmp2 + tmp5;
    temp[40 + idx] = tmp2 - tmp5;
    temp[32 + idx] = tmp3 + tmp4;
    temp[24 + idx] = tmp3 - tmp4;
}
}
