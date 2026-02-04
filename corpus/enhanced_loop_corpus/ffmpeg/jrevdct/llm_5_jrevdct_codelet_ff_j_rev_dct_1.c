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

    // Remove fine-grained conditionals on d2/d6: always assume active (optimistic path)
    z1 = ((d2 + d6) * (4433));
    tmp2 = z1 + ((-d6) * (15137));
    tmp3 = z1 + ((d2) * (6270));
    tmp0 = (d0 + d4) * (((int32_t)1) << 13);
    tmp1 = (d0 - d4) * (((int32_t)1) << 13);
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Replace complex control tree with prioritized early exits instead of deep nesting
    if (!d7 && !d5 && !d3 && !d1) {
        tmp0 = tmp1 = tmp2 = tmp3 = 0;
    }
    else if (!d7 && !d5 && !d3) {  // Only d1 is non-zero
        tmp0 = ((d1) * (2260));
        tmp1 = ((d1) * (6436));
        tmp2 = ((d1) * (9633));
        tmp3 = ((d1) * (11363));
    }
    else if (!d7 && !d5) {  // d3 or d1 active
        if (d3 && d1) {
            int32_t z5 = d1 + d3;
            tmp3 = ((d1) * (1730));
            tmp2 = ((-d3) * (11893));
            int32_t z1 = ((d1) * (8697));
            int32_t z2 = ((-d3) * (17799));
            int32_t z4 = z5 * (6436);
            z5 *= 9633;
            tmp0 = z1 - z4;
            tmp1 = z2 + z4;
            tmp2 += z5;
            tmp3 += z5;
        } else if (d3) {
            tmp0 = ((-d3) * (6436));
            tmp1 = ((-d3) * (11363));
            tmp2 = ((-d3) * (2260));
            tmp3 = ((d3) * (9633));
        } else {
            tmp0 = ((d1) * (2260));
            tmp1 = ((d1) * (6436));
            tmp2 = ((d1) * (9633));
            tmp3 = ((d1) * (11363));
        }
    }
    else {
        // Fall back to full computation only when higher coefficients exist
        z1 = d7 + d1;
        z2 = d5 + d3;
        z3 = d7 + d3;
        z4 = d5 + d1;
        z5 = ((z3 + z4) * (9633));
        tmp0 = ((d7) * (2446)) + ((-z1) * (7373)) + ((-z3) * (16069)) + z5;
        tmp1 = ((d5) * (16819)) + ((-z2) * (20995)) + ((-z4) * (3196)) + z5;
        tmp2 = ((d3) * (25172)) + ((-z2) * (20995)) + ((-z3) * (16069)) + z5;
        tmp3 = ((d1) * (12299)) + ((-z1) * (7373)) + ((-z4) * (3196)) + z5;
    }

    // Store results with rounding shift
    dataptr[8 * 0] = (int16_t)(((tmp10 + tmp3) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 7] = (int16_t)(((tmp10 - tmp3) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 1] = (int16_t)(((tmp11 + tmp2) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 6] = (int16_t)(((tmp11 - tmp2) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 2] = (int16_t)(((tmp12 + tmp1) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 5] = (int16_t)(((tmp12 - tmp1) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 3] = (int16_t)(((tmp13 + tmp0) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr[8 * 4] = (int16_t)(((tmp13 - tmp0) + (((int32_t)1) << ((13 + 2 + 3) - 1))) >> (13 + 2 + 3));
    dataptr++;
}
}
