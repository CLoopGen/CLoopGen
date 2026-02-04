#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp0;
extern int32_t tmp1;
extern int32_t tmp2;
extern int32_t tmp3;
extern int32_t tmp10;
extern int32_t tmp11;
extern int32_t tmp12;
extern int32_t tmp13;
extern int32_t z1;
extern int32_t z2;
extern int32_t z3;
extern int32_t z4;
extern int32_t z5;
extern int32_t d0;
extern int32_t d1;
extern int32_t d2;
extern int32_t d3;
extern int32_t d4;
extern int32_t d5;
extern int32_t d6;
extern int32_t d7;
extern int16_t *dataptr;
extern int rowctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rowctr = 8 - 1; rowctr >= 0; rowctr--) {
    // Reorder memory loads to create different access pattern (still valid)
    d7 = dataptr[8 * 7];
    d6 = dataptr[8 * 6];
    d5 = dataptr[8 * 5];
    d4 = dataptr[8 * 4];
    d3 = dataptr[8 * 3];
    d2 = dataptr[8 * 2];
    d1 = dataptr[8 * 1];
    d0 = dataptr[8 * 0];

    // Introduce WAW dependency: write tmp values early and refine later
    tmp0 = (d0 + d4) << 13;
    tmp1 = (d0 - d4) << 13;
    tmp2 = 0;
    tmp3 = 0;

    if (d6) {
        if (d2) {
            z1 = (d2 + d6) * 4433;
            tmp2 = z1 - (d6 * 15137);
            tmp3 = z1 + (d2 * 6270);
        } else {
            tmp2 = -d6 * 10703;
            tmp3 = d6 * 4433;
        }
    } else if (d2) {
        tmp2 = d2 * 4433;
        tmp3 = d2 * 10703;
    } else {
        tmp3 = tmp0;  // reuse for symmetry, will be overwritten
    }

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Eliminate deep nesting in second block by precomputing masks and using arithmetic blending
    int m7 = (d7 != 0);
    int m5 = (d5 != 0);
    int m3 = (d3 != 0);
    int m1 = (d1 != 0);

    // Use conditional evaluation via multiplication to remove branches (data-driven)
    tmp0 = m7 * (d7 * 2446) + (!m7 & m5) * (-d5 * 4176) + (!m7 & !m5 & m3) * (-d3 * 6436) + (!m7 & !m5 & !m3 & m1) * (d1 * 2260) + (!m7 & !m5 & !m3 & !m1) * 0;
    tmp1 = m5 * (d5 * 16819) + (!m5 & m3) * (-d3 * 11363) + (!m5 & !m3 & m1) * (-d1 * 7373) + (!m5 & !m3 & !m1 & m7) * (d7 * 9633) + (!m7 & !m5 & !m3 & !m1) * 0;
    tmp2 = m3 * (d3 * 25172) + (!m3 & m5) * (d5 * 9102) + (!m3 & !m5 & m7) * (-d7 * 6436) + (!m3 & !m5 & !m7 & m1) * (d1 * 9633) + (!m7 & !m5 & !m3 & !m1) * 0;
    tmp3 = m1 * (d1 * 12299) + (!m1 & m3) * (d3 * 9633) + (!m1 & !m3 & m5) * (d5 * 6436) + (!m1 & !m3 & !m5 & m7) * (d7 * 2260) + (!m7 & !m5 & !m3 & !m1) * 0;

    // Add synthetic cross-term dependencies to increase data coupling
    if (m7 | m5 | m3 | m1) {
        int mix = ((tmp0 ^ tmp2) + (tmp1 ^ tmp3)) >> 16;
        tmp0 += (mix * 100);
        tmp3 -= (mix * 50);
    }

    // Final store with same rounding semantics
    int round_shift = 13 + 2 + 3;
    int rounding = 1 << (round_shift - 1);

    dataptr[8 * 0] = (int16_t)((tmp10 + tmp3 + rounding) >> round_shift);
    dataptr[8 * 7] = (int16_t)((tmp10 - tmp3 + rounding) >> round_shift);
    dataptr[8 * 1] = (int16_t)((tmp11 + tmp2 + rounding) >> round_shift);
    dataptr[8 * 6] = (int16_t)((tmp11 - tmp2 + rounding) >> round_shift);
    dataptr[8 * 2] = (int16_t)((tmp12 + tmp1 + rounding) >> round_shift);
    dataptr[8 * 5] = (int16_t)((tmp12 - tmp1 + rounding) >> round_shift);
    dataptr[8 * 3] = (int16_t)((tmp13 + tmp0 + rounding) >> round_shift);
    dataptr[8 * 4] = (int16_t)((tmp13 - tmp0 + rounding) >> round_shift);

    dataptr++;
}
}
