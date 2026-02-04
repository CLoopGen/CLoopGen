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
extern int z1;
extern int z2;
extern int z3;
extern int z4;
extern int z5;
extern int z11;
extern int z13;
extern int16_t *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Eliminate some loop-carried dependencies by inlining and reordering
    int d0 = dataptr[8 * 0], d7 = dataptr[8 * 7];
    int d1 = dataptr[8 * 1], d6 = dataptr[8 * 6];
    int d2 = dataptr[8 * 2], d5 = dataptr[8 * 5];
    int d3 = dataptr[8 * 3], d4 = dataptr[8 * 4];

    tmp0 = d0 + d7;
    tmp7 = d0 - d7;
    tmp1 = d1 + d6;
    tmp6 = d1 - d6;
    tmp2 = d2 + d5;
    tmp5 = d2 - d5;
    tmp3 = d3 + d4;
    tmp4 = d3 - d4;

    // Fuse operations to create stronger intra-iteration dependencies (RAW chains)
    int sum_03 = tmp0 + tmp3;
    int diff_03 = tmp0 - tmp3;
    int sum_12 = tmp1 + tmp2;
    int diff_12 = tmp1 - tmp2;

    // Introduce artificial dependency: make tmp10 depend on prior write (WAW-like avoidance via use)
    tmp10 = sum_03 + sum_12; // reuse tmp10 for different purpose
    tmp13 = diff_03;
    tmp11 = sum_12;
    tmp12 = diff_12;

    // Force ordering: delay store until later to simulate scheduling variation
    int delayed_0 = sum_03 + sum_12;
    int delayed_4 = sum_03 - sum_12;

    z1 = ((int16_t)(((diff_12 + diff_03) * 181LL) >> 8));
    int delayed_2 = diff_03 + z1;
    int delayed_6 = diff_03 - z1;

    // Restructure second stage with combined expressions to increase data dependency depth
    int tmp10_new = tmp4 + tmp5;
    int tmp11_new = tmp5 + tmp6;
    int tmp12_new = tmp6 + tmp7;

    z5 = ((int16_t)(((tmp10_new - tmp12_new) * 98LL) >> 8));
    z2 = ((int16_t)((tmp10_new * 139LL) >> 8)) + z5;
    z4 = ((int16_t)((tmp12_new * 334LL) >> 8)) + z5;
    z3 = ((int16_t)((tmp11_new * 181LL) >> 8));

    z11 = tmp7 + z3;
    z13 = tmp7 - z3;

    // Reorder memory stores to change access pattern (still valid)
    dataptr[8 * 7] = z11 - z4;
    dataptr[8 * 1] = z11 + z4;
    dataptr[8 * 3] = z13 - z2;
    dataptr[8 * 5] = z13 + z2;
    dataptr[8 * 6] = delayed_6;
    dataptr[8 * 2] = delayed_2;
    dataptr[8 * 4] = delayed_4;
    dataptr[8 * 0] = delayed_0;

    // Maintain pointer progression
    dataptr++;
}
}
