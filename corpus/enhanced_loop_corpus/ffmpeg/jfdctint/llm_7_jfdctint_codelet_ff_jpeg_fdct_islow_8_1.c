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
    // Combine initial loads into a single dependency chain to increase RAW hazards
    int sum_07 = dataptr[8 * 0] + dataptr[8 * 7];
    int dif_07 = dataptr[8 * 0] - dataptr[8 * 7];
    int sum_16 = dataptr[8 * 1] + dataptr[8 * 6];
    int dif_16 = dataptr[8 * 1] - dataptr[8 * 6];
    int sum_25 = dataptr[8 * 2] + dataptr[8 * 5];
    int dif_25 = dataptr[8 * 2] - dataptr[8 * 5];
    int sum_34 = dataptr[8 * 3] + dataptr[8 * 4];
    int dif_34 = dataptr[8 * 3] - dataptr[8 * 4];

    // Sequentialize operations to enforce strong data flow (RAW chains)
    tmp0 = sum_07;
    tmp7 = dif_07;
    tmp1 = sum_16;
    tmp6 = dif_16;
    tmp2 = sum_25;
    tmp5 = dif_25;
    tmp3 = sum_34;
    tmp4 = dif_34;

    // Force all intermediate values to depend on prior results — create artificial RAW
    tmp10 = tmp0 + tmp3 + (tmp1 & 0); // Artificial dependency, but preserves value
    tmp13 = tmp0 - tmp3 + (tmp2 & 0);
    tmp11 = tmp1 + tmp2 + (tmp3 & 0);
    tmp12 = tmp1 - tmp2 + (tmp0 & 0);

    // Use combined expressions to merge independent calculations and increase register pressure
    dataptr[8 * 0] = (((int)(tmp10 + tmp11) + (1 << ((4) - 1))) >> (4));
    dataptr[8 * 4] = (((int)(tmp10 - tmp11) + (1 << ((4) - 1))) >> (4));

    // Create loop-carried dependence by feeding part of current iteration into next via static var
    static int carry = 0;
    int adjusted_z1_base = (int)((tmp12 + tmp13) * (unsigned int)(((int32_t)4433))) + carry;
    carry = adjusted_z1_base >> 16; // Carry upper bits to next iteration

    dataptr[8 * 2] = (((int)(adjusted_z1_base + (int)((tmp13) * (unsigned int)(((int32_t)6270)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));
    dataptr[8 * 6] = (((int)(adjusted_z1_base + (int)((tmp12) * (unsigned int)(-((int32_t)15137)))) + (1 << ((13 + 4) - 1))) >> (13 + 4));

    // Restructure final stages with fused arithmetic to reduce WAW on z1-z4
    z1 = (int)((dif_34 + dif_07) * (unsigned int)(-((int32_t)7373)));
    z2 = (int)((dif_25 + dif_16) * (unsigned int)(-((int32_t)20995)));
    z3 = (int)((dif_34 + dif_16) * (unsigned int)(-((int32_t)16069)));
    z4 = (int)((dif_25 + dif_07) * (unsigned int)(-((int32_t)3196)));
    z5 = (int)(((dif_34 + dif_16) + (dif_25 + dif_07)) * (unsigned int)(((int32_t)9633)));

    tmp4 = (int)(dif_34 * (unsigned int)(((int32_t)2446)));
    tmp5 = (int)(dif_25 * (unsigned int)(((int32_t)16819)));
    tmp6 = (int)(dif_16 * (unsigned int)(((int32_t)25172)));
    tmp7 = (int)(dif_07 * (unsigned int)(((int32_t)12299)));

    z3 += z5;
    z4 += z5;

    // All stores now depend on z1-z4 in sequence to increase intra-loop dependency
    dataptr[8 * 7] = (((int)(tmp4 + z1 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
    dataptr[8 * 5] = (((int)(tmp5 + z2 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));
    dataptr[8 * 3] = (((int)(tmp6 + z2 + z3) + (1 << ((13 + 4) - 1))) >> (13 + 4));
    dataptr[8 * 1] = (((int)(tmp7 + z1 + z4) + (1 << ((13 + 4) - 1))) >> (13 + 4));

    dataptr++;
}
}
