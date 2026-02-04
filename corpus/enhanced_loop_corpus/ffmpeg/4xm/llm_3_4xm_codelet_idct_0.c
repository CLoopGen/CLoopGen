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
int offsets[8] = {0, 8, 16, 24, 32, 40, 48, 56};
for (i = 0; i < 8; i++) {
    int base = offsets[i];
    tmp10 = block[base + 0] + block[base + 32];
    tmp11 = block[base + 0] - block[base + 32];
    tmp13 = block[base + 16] + block[base + 48];
    tmp12 = ((int)((block[base + 16] - block[base + 48]) * (unsigned int)(92682)) >> 16) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    z13 = block[base + 40] + block[base + 24];
    z10 = block[base + 40] - block[base + 24];
    z11 = block[base + 8] + block[base + 56];
    z12 = block[base + 8] - block[base + 56];
    tmp7 = z11 + z13;
    tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
    z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
    tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
    tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    temp[base + 0] = tmp0 + tmp7;
    temp[base + 56] = tmp0 - tmp7;
    temp[base + 8] = tmp1 + tmp6;
    temp[base + 48] = tmp1 - tmp6;
    temp[base + 16] = tmp2 + tmp5;
    temp[base + 40] = tmp2 - tmp5;
    temp[base + 32] = tmp3 + tmp4;
    temp[base + 24] = tmp3 - tmp4;
}
}
