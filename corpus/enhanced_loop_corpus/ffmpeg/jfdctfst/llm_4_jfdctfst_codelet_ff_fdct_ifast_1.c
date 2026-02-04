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
extern int z2;
extern int z3;
extern int z4;
extern int z5;
extern int z11;
extern int z13;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    if (dataptr[8 * 0] == 0 && dataptr[8 * 7] == 0) {
        dataptr[8 * 0] = 0;
        dataptr[8 * 4] = 0;
        dataptr[8 * 2] = 0;
        dataptr[8 * 6] = 0;
        dataptr[8 * 5] = 0;
        dataptr[8 * 3] = 0;
        dataptr[8 * 1] = 0;
        dataptr[8 * 7] = 0;
    } else {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
        tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
        tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
        tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
        tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
        tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
        tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
        tmp4 = dataptr[8 * 3] - dataptr[8 * 4];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        dataptr[8 * 0] = tmp10 + tmp11;
        dataptr[8 * 4] = tmp10 - tmp11;
        z1 = ((int16_t)(((tmp12 + tmp13) * (((int32_t)181))) >> (8)));
        dataptr[8 * 2] = tmp13 + z1;
        dataptr[8 * 6] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = ((int16_t)(((tmp10 - tmp12) * (((int32_t)98))) >> (8)));
        z2 = ((int16_t)(((tmp10) * (((int32_t)139))) >> (8))) + z5;
        z4 = ((int16_t)(((tmp12) * (((int32_t)334))) >> (8))) + z5;
        z3 = ((int16_t)(((tmp11) * (((int32_t)181))) >> (8)));
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        dataptr[8 * 5] = z13 + z2;
        dataptr[8 * 3] = z13 - z2;
        dataptr[8 * 1] = z11 + z4;
        dataptr[8 * 7] = z11 - z4;
    }
    dataptr++;
}
}
