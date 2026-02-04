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



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    int d0 = dataptr[0], d1 = dataptr[1], d2 = dataptr[2], d3 = dataptr[3];
    int d4 = dataptr[4], d5 = dataptr[5], d6 = dataptr[6], d7 = dataptr[7];

    tmp0 = d0 + d7;
    tmp7 = d0 - d7;
    tmp1 = d1 + d6;
    tmp6 = d1 - d6;
    tmp2 = d2 + d5;
    tmp5 = d2 - d5;
    tmp3 = d3 + d4;
    tmp4 = d3 - d4;

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    dataptr[0] = (int16_t)((tmp10 + tmp11) * 2);
    dataptr[4] = (int16_t)((tmp10 - tmp11) * 2);

    int w12_13 = (int)((tmp12 + tmp13) * (unsigned int)(4433U));
    int term2 = (int)(w12_13 + (int)(tmp13 * 6270U) + (1 << 11)) >> 12;
    int term6 = (int)(w12_13 + (int)(tmp12 * (unsigned int)(-15137)) + (1 << 11)) >> 12;
    dataptr[2] = (int16_t)term2;
    dataptr[6] = (int16_t)term6;

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    z5 = (int)((z3 + z4) * 9633U);

    tmp4 = (int)(tmp4 * 2446U);
    tmp5 = (int)(tmp5 * 16819U);
    tmp6 = (int)(tmp6 * 25172U);
    tmp7 = (int)(tmp7 * 12299U);

    z1 = (int)(z1 * (unsigned int)(-7373));
    z2 = (int)(z2 * (unsigned int)(-20995));
    z3 = (int)(z3 * (unsigned int)(-16069));
    z4 = (int)(z4 * (unsigned int)(-3196));

    z3 += z5;
    z4 += z5;

    dataptr[7] = (int16_t)((tmp4 + z1 + z3 + (1 << 11)) >> 12);
    dataptr[5] = (int16_t)((tmp5 + z2 + z4 + (1 << 11)) >> 12);
    dataptr[3] = (int16_t)((tmp6 + z2 + z3 + (1 << 11)) >> 12);
    dataptr[1] = (int16_t)((tmp7 + z1 + z4 + (1 << 11)) >> 12);

    dataptr += 8;
}
}
