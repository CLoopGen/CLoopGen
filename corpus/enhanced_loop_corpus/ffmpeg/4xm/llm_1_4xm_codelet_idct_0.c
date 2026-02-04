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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
        int idx = i * 4 + j;
        tmp10 = block[8 * 0 + idx] + block[8 * 4 + idx];
        tmp11 = block[8 * 0 + idx] - block[8 * 4 + idx];
        tmp13 = block[8 * 2 + idx] + block[8 * 6 + idx];
        tmp12 = ((int)((block[8 * 2 + idx] - block[8 * 6 + idx]) * (unsigned int)(92682)) >> 16) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = block[8 * 5 + idx] + block[8 * 3 + idx];
        z10 = block[8 * 5 + idx] - block[8 * 3 + idx];
        z11 = block[8 * 1 + idx] + block[8 * 7 + idx];
        z12 = block[8 * 1 + idx] - block[8 * 7 + idx];
        tmp7 = z11 + z13;
        tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
        z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
        tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
        tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;
        temp[8 * 0 + idx] = tmp0 + tmp7;
        temp[8 * 7 + idx] = tmp0 - tmp7;
        temp[8 * 1 + idx] = tmp1 + tmp6;
        temp[8 * 6 + idx] = tmp1 - tmp6;
        temp[8 * 2 + idx] = tmp2 + tmp5;
        temp[8 * 5 + idx] = tmp2 - tmp5;
        temp[8 * 4 + idx] = tmp3 + tmp4;
        temp[8 * 3 + idx] = tmp3 - tmp4;
    }
}
}
