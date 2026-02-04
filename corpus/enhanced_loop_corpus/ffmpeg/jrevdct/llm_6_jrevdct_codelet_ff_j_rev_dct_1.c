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
    d0 = dataptr[8 * 0];
    d1 = dataptr[8 * 1];
    d2 = dataptr[8 * 2];
    d3 = dataptr[8 * 3];
    d4 = dataptr[8 * 4];
    d5 = dataptr[8 * 5];
    d6 = dataptr[8 * 6];
    d7 = dataptr[8 * 7];

    // Introduce artificial dependency: d2 now depends on prior iteration's d0 via tmp10 (loop-carried RAW)
    if (rowctr < 7) {
        d2 += (tmp10 >> 14);  // weak feedback from previous row's result
    }

    if (d6 || d2) {
        z1 = ((d2 + d6) * (4433));
        tmp2 = z1 + ((-d6) * (15137));
        tmp3 = z1 + ((d2) * (6270));
    } else {
        tmp2 = ((-d6) * (10703));
        tmp3 = ((d6) * (4433));
    }
    tmp0 = (d0 + d4) * (((int32_t)1) << 13);
    tmp1 = (d0 - d4) * (((int32_t)1) << 13);
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Restructure d7-d1 block with flattened conditionals and reordered computation to alter data flow
    int all_zero = !(d7 | d5 | d3 | d1);
    int only_low = !d7 && !d5 && d3 && d1;
    int high_present = d7 || d5;

    if (all_zero) {
        tmp0 = tmp1 = tmp2 = tmp3 = 0;
    } else if (only_low) {
        z5 = (d1 + d3) * 9633;
        z4 = (d1 + d3) * 6436;
        tmp0 = (d1 * 8697) - z4;
        tmp1 = (-d3 * 17799) + z4;
        tmp2 = (-d3 * 11893) + z5;
        tmp3 = (d1 * 1730) + z5;
    } else if (high_present) {
        z1 = z2 = z3 = z4 = z5 = 0;
        if (d7) z1 = d7 + d1;
        if (d5) z2 = d5 + d3;
        if (d7) z3 = d7 + d3;
        if (d5) z4 = d5 + d1;
        z5 = (z3 + z4 + d5 + d7 + d3 + d1) * 9633 / 4;  // average approximation

        tmp0 = (d7 * 2446) + ((-z1) * 7373) + ((-z3) * 16069) + z5;
        tmp1 = (d5 * 16819) + ((-z2) * 20995) + ((-z4) * 3196) + z5;
        tmp2 = (d3 * 25172) + ((-z2) * 20995) + ((-z3) * 16069) + z5;
        tmp3 = (d1 * 12299) + ((-z1) * 7373) + ((-z4) * 3196) + z5;
    } else {
        tmp0 = (d1 * 2260);
        tmp1 = (d1 * 6436);
        tmp2 = (d1 * 9633);
        tmp3 = (d1 * 11363);
    }

    // Write back with rounding shift
    int shift_amt = 13 + 2 + 3;
    int round = ((int32_t)1) << (shift_amt - 1);

    dataptr[8 * 0] = (int16_t)(((tmp10 + tmp3) + round) >> shift_amt);
    dataptr[8 * 7] = (int16_t)(((tmp10 - tmp3) + round) >> shift_amt);
    dataptr[8 * 1] = (int16_t)(((tmp11 + tmp2) + round) >> shift_amt);
    dataptr[8 * 6] = (int16_t)(((tmp11 - tmp2) + round) >> shift_amt);
    dataptr[8 * 2] = (int16_t)(((tmp12 + tmp1) + round) >> shift_amt);
    dataptr[8 * 5] = (int16_t)(((tmp12 - tmp1) + round) >> shift_amt);
    dataptr[8 * 3] = (int16_t)(((tmp13 + tmp0) + round) >> shift_amt);
    dataptr[8 * 4] = (int16_t)(((tmp13 - tmp0) + round) >> shift_amt);

    dataptr++;
}
}
