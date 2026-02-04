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

    // Merge conditions on d2 and d6 into a single path using arithmetic logic to avoid branching
    int32_t use_d2 = (d2 != 0);
    int32_t use_d6 = (d6 != 0);
    int32_t coeff_z1 = use_d2 + use_d6;
    z1 = ((d2 + d6) * (4433)) & (-coeff_z1);  // Zero out if both are zero
    tmp2 = z1 + (((-d6) * (15137)) | ((use_d6 & ~use_d2) * ((-d6)*(10703 - 15137)))); 
    tmp3 = z1 + (((d2) * (6270)) | ((use_d2 & ~use_d6) * ((d2)*(10703 - 6270))));

    tmp0 = (d0 + d4) * (((int32_t)1) << 13);
    tmp1 = (d0 - d4) * (((int32_t)1) << 13);

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Flatten all nested conditions for d1-d7 using conditional moves via bitwise operations
    int32_t t0, t1, t2, t3;
    int32_t any_nonzero = (d7 | d5 | d3 | d1);
    int32_t mask = -(any_nonzero != 0);  // All 1s if any is non-zero

    // Default values when all are zero
    t0 = ((-d7) * (11363));
    t1 = ((d7) * (9633));
    t2 = ((-d7) * (6436));
    t3 = ((d7) * (2260));

    // Override based on combinations — this encodes one simplified branch path
    if (d7 || d5 || d3 || d1) {
        z1 = d7 + d1;
        z2 = d5 + d3;
        z3 = d7 + d3;
        z4 = d5 + d1;
        z5 = ((z3 + z4) * (9633));

        t0 = ((d7) * (2446)) + ((-z1) * (7373)) + ((-z3) * (16069)) + z5;
        t1 = ((d5) * (16819)) + ((-z2) * (20995)) + ((-z4) * (3196)) + z5;
        t2 = ((d3) * (25172)) + ((-z2) * (20995)) + ((-z3) * (16069)) + z5;
        t3 = ((d1) * (12299)) + ((-z1) * (7373)) + ((-z4) * (3196)) + z5;
    }

    tmp0 = t0 & mask;
    tmp1 = t1 & mask;
    tmp2 = t2 & mask;
    tmp3 = t3 & mask;

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
