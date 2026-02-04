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
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        // Modify data flow: fuse initial loads into delayed computation with reordered dependencies
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

        // Eliminate some intermediate variables by inlining expressions where possible
        int sum_03 = tmp0 + tmp3;
        int diff_03 = tmp0 - tmp3;
        int sum_12 = tmp1 + tmp2;
        int diff_12 = tmp1 - tmp2;

        dataptr[0] = (int16_t)((sum_03 + sum_12) * (1 << 4));
        dataptr[4] = (int16_t)((sum_03 - sum_12) * (1 << 4));

        // Replace z1 reuse with distinct temps to break anti-dependence (WAW hazard removed)
        unsigned int t_z1 = (int)((diff_12 + diff_03) * (unsigned int)(((int32_t)4433)));
        dataptr[2] = (int16_t)(((int)(t_z1 + (int)(diff_03 * (unsigned int)(((int32_t)6270)))) + (1 << 8)) >> 9);
        dataptr[6] = (int16_t)(((int)(t_z1 + (int)(diff_12 * (unsigned int)(-((int32_t)15137)))) + (1 << 8)) >> 9);

        // Restructure butterfly calculations with combined arithmetic to increase ILP
        int v1 = tmp4 + tmp7;
        int v2 = tmp5 + tmp6;
        int v3 = tmp4 + tmp6;
        int v4 = tmp5 + tmp7;

        int w1 = (int)(v1 * (unsigned int)(-((int32_t)7373)));
        int w2 = (int)(v2 * (unsigned int)(-((int32_t)20995)));
        int w3 = (int)(v3 * (unsigned int)(-((int32_t)16069)));
        int w4 = (int)(v4 * (unsigned int)(-((int32_t)3196)));

        int z5_val = (int)((v3 + v4) * (unsigned int)(((int32_t)9633)));
        w3 += z5_val;
        w4 += z5_val;

        // Precompute scaled components to reduce redundant casting
        int s4 = (int)(tmp4 * (unsigned int)(((int32_t)2446)));
        int s5 = (int)(tmp5 * (unsigned int)(((int32_t)16819)));
        int s6 = (int)(tmp6 * (unsigned int)(((int32_t)25172)));
        int s7 = (int)(tmp7 * (unsigned int)(((int32_t)12299)));

        dataptr[7] = (int16_t)(((s4 + w1 + w3) + (1 << 8)) >> 9);
        dataptr[5] = (int16_t)(((s5 + w2 + w4) + (1 << 8)) >> 9);
        dataptr[3] = (int16_t)(((s6 + w2 + w3) + (1 << 8)) >> 9);
        dataptr[1] = (int16_t)(((s7 + w1 + w4) + (1 << 8)) >> 9);

        dataptr += 8;
    }
}
