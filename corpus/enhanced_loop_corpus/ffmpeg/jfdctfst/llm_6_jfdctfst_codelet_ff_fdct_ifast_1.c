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
    tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
    tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
    tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
    tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
    tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
    tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

    // Introduce temporary variables to break and rewire dependencies
    int t0 = tmp0, t3 = tmp3, t1 = tmp1, t2 = tmp2;
    tmp10 = t0 + t3;
    tmp13 = t0 - t3;
    tmp11 = t1 + t2;
    tmp12 = t1 - t2;

    // Reorder computations to modify RAW/WAW dependencies
    int save_0 = dataptr[8 * 0];
    int save_4 = dataptr[8 * 4];
    dataptr[8 * 0] = tmp10 + tmp11;
    dataptr[8 * 4] = tmp10 - tmp11;

    // Modify dependency chain by precomputing scaled values earlier
    int scale_181_8 = ((int32_t)181) >> 8;
    z1 = ((int16_t)(((tmp12 + tmp13) * (((int32_t)181))) >> (8)));

    // Break WAW on dataptr[8*2] and dataptr[8*6] via intermediate
    int result_2 = tmp13 + z1;
    int result_6 = tmp13 - z1;
    dataptr[8 * 2] = result_2;
    dataptr[8 * 6] = result_6;

    // Restructure second half with local temporaries to reduce loop-carried dependency
    int a = tmp4 + tmp5;
    int b = tmp5 + tmp6;
    int c = tmp6 + tmp7;
    z5 = ((int16_t)(((a - c) * (((int32_t)98))) >> (8)));
    z2 = ((int16_t)((a * (((int32_t)139))) >> (8))) + z5;
    z4 = ((int16_t)((c * (((int32_t)334))) >> (8))) + z5;
    z3 = ((int16_t)((b * (((int32_t)181))) >> (8)));

    int z11_val = tmp7 + z3;
    int z13_val = tmp7 - z3;

    dataptr[8 * 5] = z13_val + z2;
    dataptr[8 * 3] = z13_val - z2;
    dataptr[8 * 1] = z11_val + z4;
    dataptr[8 * 7] = z11_val - z4;

    dataptr++;
}
}
