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



void loop() {
    for (i = 0; i < 16; i += 2) {
        int offset1 = 8 * 0 + i, offset2 = 8 * 1 + i, offset3 = 8 * 2 + i, offset4 = 8 * 3 + i;
        int offset5 = 8 * 4 + i, offset6 = 8 * 5 + i, offset7 = 8 * 6 + i, offset8 = 8 * 7 + i;

        tmp10 = block[offset1] + block[offset5];
        tmp11 = block[offset1] - block[offset5];
        tmp13 = block[offset3] + block[offset7];
        tmp12 = ((int)((block[offset3] - block[offset7]) * (unsigned int)(92682)) >> 16) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = block[offset6] + block[offset4];
        z10 = block[offset6] - block[offset4];
        z11 = block[offset2] + block[offset8];
        z12 = block[offset2] - block[offset8];

        tmp7 = z11 + z13;
        tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
        z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
        tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
        tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        temp[offset1] = tmp0 + tmp7;
        temp[offset8] = tmp0 - tmp7;
        temp[offset2] = tmp1 + tmp6;
        temp[offset7] = tmp1 - tmp6;
        temp[offset3] = tmp2 + tmp5;
        temp[offset6] = tmp2 - tmp5;
        temp[offset5] = tmp3 + tmp4;
        temp[offset4] = tmp3 - tmp4;

        if (i + 1 < 8) {
            int j = i + 1;
            tmp10 = block[8 * 0 + j] + block[8 * 4 + j];
            tmp11 = block[8 * 0 + j] - block[8 * 4 + j];
            tmp13 = block[8 * 2 + j] + block[8 * 6 + j];
            tmp12 = ((int)((block[8 * 2 + j] - block[8 * 6 + j]) * (unsigned int)(92682)) >> 16) - tmp13;
            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            z13 = block[8 * 5 + j] + block[8 * 3 + j];
            z10 = block[8 * 5 + j] - block[8 * 3 + j];
            z11 = block[8 * 1 + j] + block[8 * 7 + j];
            z12 = block[8 * 1 + j] - block[8 * 7 + j];

            tmp7 = z11 + z13;
            tmp11 = ((int)((z11 - z13) * (unsigned int)(92682)) >> 16);
            z5 = ((int)((z10 + z12) * (unsigned int)(121095)) >> 16);
            tmp10 = ((int)((z12) * (unsigned int)(70936)) >> 16) - z5;
            tmp12 = ((int)((z10) * (unsigned int)(-171254)) >> 16) + z5;

            tmp6 = tmp12 - tmp7;
            tmp5 = tmp11 - tmp6;
            tmp4 = tmp10 + tmp5;

            temp[8 * 0 + j] = tmp0 + tmp7;
            temp[8 * 7 + j] = tmp0 - tmp7;
            temp[8 * 1 + j] = tmp1 + tmp6;
            temp[8 * 6 + j] = tmp1 - tmp6;
            temp[8 * 2 + j] = tmp2 + tmp5;
            temp[8 * 5 + j] = tmp2 - tmp5;
            temp[8 * 4 + j] = tmp3 + tmp4;
            temp[8 * 3 + j] = tmp3 - tmp4;
        }
    }
}
