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
extern unsigned int z1;
extern unsigned int z2;
extern unsigned int z3;
extern unsigned int z4;
extern unsigned int z5;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 16 - 1; ctr >= 0; ctr--) {
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

        dataptr[8 * 0] = (((tmp10 + tmp11 + 2) >> 2));
        dataptr[8 * 4] = (((tmp10 - tmp11 + 2) >> 2));

        z1 = ((tmp12 + tmp13) * 4433U);
        dataptr[8 * 2] = (((z1 + tmp13 * 6270U) + (1 << 14)) >> 15);
        dataptr[8 * 6] = (((z1 + tmp12 * (unsigned int)(-15137)) + (1 << 14)) >> 15);

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * 9633U;

        tmp4 = tmp4 * 2446U;
        tmp5 = tmp5 * 16819U;
        tmp6 = tmp6 * 25172U;
        tmp7 = tmp7 * 12299U;

        z1 *= -7373U;
        z2 *= -20995U;
        z3 *= -16069U;
        z4 *= -3196U;

        z3 += z5;
        z4 += z5;

        dataptr[8 * 7] = ((tmp4 + z1 + z3 + (1 << 14)) >> 15);
        dataptr[8 * 5] = ((tmp5 + z2 + z4 + (1 << 14)) >> 15);
        dataptr[8 * 3] = ((tmp6 + z2 + z3 + (1 << 14)) >> 15);
        dataptr[8 * 1] = ((tmp7 + z1 + z4 + (1 << 14)) >> 15);

        dataptr++;
    }
}
