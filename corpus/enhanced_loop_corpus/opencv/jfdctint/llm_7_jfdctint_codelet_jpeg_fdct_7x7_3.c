#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++) {
    INT32 d0 = dataptr[8 * 0], d1 = dataptr[8 * 1], d2 = dataptr[8 * 2], d3 = dataptr[8 * 3];
    INT32 d4 = dataptr[8 * 4], d5 = dataptr[8 * 5], d6 = dataptr[8 * 6];

    tmp0 = d0 + d6;
    tmp1 = d1 + d5;
    tmp2 = d2 + d4;
    tmp3 = d3;
    tmp10 = d0 - d6;
    tmp11 = d1 - d5;
    tmp12 = d2 - d4;

    z1 = tmp0 + tmp2;
    z1 = ((((z1 + tmp1 + tmp3) * (((INT32)((1.3061224490000001) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2);

    tmp3 += tmp3;
    tmp3 += tmp3;

    INT32 diff_02 = tmp0 - tmp2;
    INT32 diff_12 = tmp1 - tmp2;
    INT32 sum_10_11 = tmp10 + tmp11;
    INT32 diff_10_11 = tmp10 - tmp11;
    INT32 sum_11_12 = tmp11 + tmp12;
    INT32 sum_10_12 = tmp10 + tmp12;

    z1 = ((z1 - tmp3) * (((INT32)((0.46178402000000002) * (((INT32)1) << 13) + 0.5)))) +
         ((diff_02) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5)))) +
         ((diff_12) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));

    z1 = (z1 + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2);

    INT32 partA = ((sum_10_11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5)))) -
                  ((diff_10_11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5)))) +
                  ((sum_10_12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5))));

    INT32 partB = ((sum_10_11) * (((INT32)((1.221765677) * (((INT32)1) << 13) + 0.5)))) +
                  ((diff_10_11) * (((INT32)((0.222383464) * (((INT32)1) << 13) + 0.5)))) +
                  ((sum_11_12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5))));

    INT32 partC = ((sum_11_12) * (-((INT32)((1.800824523) * (((INT32)1) << 13) + 0.5)))) +
                  ((sum_10_12) * (((INT32)((0.80144230999999999) * (((INT32)1) << 13) + 0.5)))) +
                  ((tmp12) * (((INT32)((2.4435313550000002) * (((INT32)1) << 13) + 0.5))));

    INT32 final_diff = tmp0 - tmp1;
    INT32 z2 = ((final_diff) * (((INT32)((1.1516705089999999) * (((INT32)1) << 13) + 0.5))));
    INT32 z3 = ((tmp1 - tmp3/2) * (((INT32)((0.41102644599999999) * (((INT32)1) << 13) + 0.5))));
    INT32 cross_term = ((tmp1 - tmp3) * (((INT32)((0.92356804100000001) * (((INT32)1) << 13) + 0.5))));

    INT32 w4 = (z2 + z3 - cross_term + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2);
    INT32 w6 = (z1 - ((diff_02) * (((INT32)((1.2024280839999999) * (((INT32)1) << 13) + 0.5)))) + z2 + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2);

    dataptr[8 * 0] = (DCTELEM)z1;
    dataptr[8 * 2] = (DCTELEM)z1;
    dataptr[8 * 4] = (DCTELEM)w4;
    dataptr[8 * 6] = (DCTELEM)w6;
    dataptr[8 * 1] = (DCTELEM)((partA + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)((partB + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
    dataptr[8 * 5] = (DCTELEM)((partC + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

    dataptr++;
}
}
