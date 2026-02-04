#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

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
    register uint8_t *idataptr = (uint8_t *)dataptr;
    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];
    d1 = dataptr[4];
    d3 = dataptr[5];
    d5 = dataptr[6];
    d7 = dataptr[7];

    // Removed the complex zero-check branch and always proceed with computation
    // This creates a more predictable execution path without early continuation

    if (d6 || d2) {
        z1 = ((d2 + d6) * (4433));
        tmp2 = z1 + ((-d6) * (15137));
        tmp3 = z1 + ((d2) * (6270));
    } else {
        tmp2 = ((-d6) * (10703)) + ((d2) * (4433));  // Combined assignment
        tmp3 = ((d6) * (4433)) + ((d2) * (10703));
    }

    tmp0 = (d0 + d4) * (((int32_t)1) << 13);
    tmp1 = (d0 - d4) * (((int32_t)1) << 13);
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Unified butterfly computation without nested conditionals
    // Use arithmetic blending instead of branching on d7, d5, d3, d1
    int coeff_d7 = (d7 != 0) ? 1 : 0;
    int coeff_d5 = (d5 != 0) ? 1 : 0;
    int coeff_d3 = (d3 != 0) ? 1 : 0;
    int coeff_d1 = (d1 != 0) ? 1 : 0;

    z1 = coeff_d7 * d7 + coeff_d1 * d1;
    z2 = coeff_d5 * d5 + coeff_d3 * d3;
    z3 = coeff_d7 * d7 + coeff_d3 * d3;
    z4 = coeff_d5 * d5 + coeff_d1 * d1;
    z5 = ((z3 + z4) * (9633));

    tmp0 = coeff_d7 * ((d7) * (2446)) + (1 - coeff_d7) * 0;
    tmp1 = coeff_d5 * ((d5) * (16819)) + (1 - coeff_d5) * 0;
    tmp2 = coeff_d3 * ((d3) * (25172)) + (1 - coeff_d3) * 0;
    tmp3 = coeff_d1 * ((d1) * (12299)) + (1 - coeff_d1) * 0;

    z1 = (-z1) * (7373);
    z2 = (-z2) * (20995);
    z3 = (-z3) * (16069);
    z4 = (-z4) * (3196);

    z3 += z5;
    z4 += z5;

    tmp0 += z1 + z3;
    tmp1 += z2 + z4;
    tmp2 += z2 + z3;
    tmp3 += z1 + z4;

    dataptr[0] = (int16_t)(((tmp10 + tmp3) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[7] = (int16_t)(((tmp10 - tmp3) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[1] = (int16_t)(((tmp11 + tmp2) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (int16_t)(((tmp11 - tmp2) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[2] = (int16_t)(((tmp12 + tmp1) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (int16_t)(((tmp12 - tmp1) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (int16_t)(((tmp13 + tmp0) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[4] = (int16_t)(((tmp13 - tmp0) + (((int32_t)1) << ((13 - 2) - 1))) >> (13 - 2));
    dataptr += 8;
}
}
