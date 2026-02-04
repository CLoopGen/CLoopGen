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

    // Introduce temporary variables to break WAW and WAR dependencies by reordering independent computations
    int t_val0, t_val1, t_val2, t_val3;
    z1 = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433)));
    int z1_scaled_1 = (int)((tmp13) * (unsigned int)(((int32_t)6270)));
    int z1_scaled_2 = (int)((tmp12) * (unsigned int)(-((int32_t)15137)));

    t_val0 = (((int)(tmp10 + tmp11) + (1 << (((1 + 1)) - 1))) >> ((1 + 1)));
    t_val1 = (((int)(tmp10 - tmp11) + (1 << (((1 + 1)) - 1))) >> ((1 + 1)));
    t_val2 = (((int)(z1 + z1_scaled_1) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));
    t_val3 = (((int)(z1 + z1_scaled_2) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));

    z1 = tmp4 + tmp7;
    z2 = tmp5 + tmp6;
    z3 = tmp4 + tmp6;
    z4 = tmp5 + tmp7;
    int z5_base = (int)((z3 + z4) * (unsigned int)(((int32_t)9633)));

    int tmp4_scaled = (int)((tmp4) * (unsigned int)(((int32_t)2446)));
    int tmp5_scaled = (int)((tmp5) * (unsigned int)(((int32_t)16819)));
    int tmp6_scaled = (int)((tmp6) * (unsigned int)(((int32_t)25172)));
    int tmp7_scaled = (int)((tmp7) * (unsigned int)(((int32_t)12299)));
    int z1_scaled = (int)((z1) * (unsigned int)(-((int32_t)7373)));
    int z2_scaled = (int)((z2) * (unsigned int)(-((int32_t)20995)));
    int z3_scaled = (int)((z3) * (unsigned int)(-((int32_t)16069)));
    int z4_scaled = (int)((z4) * (unsigned int)(-((int32_t)3196)));

    // Store results using temporaries to eliminate write-after-write hazards with earlier writes
    dataptr[8 * 0] = t_val0;
    dataptr[8 * 4] = t_val1;
    dataptr[8 * 2] = t_val2;
    dataptr[8 * 6] = t_val3;

    z3_scaled += z5_base;
    z4_scaled += z5_base;

    dataptr[8 * 7] = (((int)(tmp4_scaled + z1_scaled + z3_scaled) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));
    dataptr[8 * 5] = (((int)(tmp5_scaled + z2_scaled + z4_scaled) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));
    dataptr[8 * 3] = (((int)(tmp6_scaled + z2_scaled + z3_scaled) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));
    dataptr[8 * 1] = (((int)(tmp7_scaled + z1_scaled + z4_scaled) + (1 << ((13 + (1 + 1)) - 1))) >> (13 + (1 + 1)));

    dataptr++;
}
}
