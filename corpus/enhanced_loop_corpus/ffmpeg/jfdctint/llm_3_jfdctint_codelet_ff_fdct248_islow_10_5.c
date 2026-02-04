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
    ptrdiff_t indices[] = {0, 2, 4, 6, 1, 3, 5, 7};
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        int16_t *row = dataptr;
        tmp0 = row[indices[0]*8] + row[indices[1]*8];
        tmp1 = row[indices[2]*8] + row[indices[3]*8];
        tmp2 = row[indices[0]*8+4*8] + row[indices[1]*8+5*8];
        tmp3 = row[indices[2]*8+6*8] + row[indices[3]*8+7*8];
        tmp4 = row[indices[0]*8] - row[indices[1]*8];
        tmp5 = row[indices[2]*8] - row[indices[3]*8];
        tmp6 = row[indices[0]*8+4*8] - row[indices[1]*8+5*8];
        tmp7 = row[indices[2]*8+6*8] - row[indices[3]*8+7*8];
        tmp10 = tmp0 + tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        tmp13 = tmp0 - tmp3;
        row[indices[0]*8] = (((int)(tmp10 + tmp11) + (1 << 1)) >> 2);
        row[indices[2]*8] = (((int)(tmp10 - tmp11) + (1 << 1)) >> 2);
        z1 = (int)((tmp12 + tmp13) * 4433U);
        row[indices[1]*8] = (((int)(z1 + tmp13 * 6270U) + (1 << 14)) >> 15);
        row[indices[3]*8] = (((int)(z1 + tmp12 * (-15137U)) + (1 << 14)) >> 15);
        tmp10 = tmp4 + tmp7;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp5 - tmp6;
        tmp13 = tmp4 - tmp7;
        row[indices[0]*8+1*8] = (((int)(tmp10 + tmp11) + (1 << 1)) >> 2);
        row[indices[2]*8+5*8] = (((int)(tmp10 - tmp11) + (1 << 1)) >> 2);
        z1 = (int)((tmp12 + tmp13) * 4433U);
        row[indices[1]*8+3*8] = (((int)(z1 + tmp13 * 6270U) + (1 << 14)) >> 15);
        row[indices[3]*8+7*8] = (((int)(z1 + tmp12 * (-15137U)) + (1 << 14)) >> 15);
        dataptr++;
    }
}
