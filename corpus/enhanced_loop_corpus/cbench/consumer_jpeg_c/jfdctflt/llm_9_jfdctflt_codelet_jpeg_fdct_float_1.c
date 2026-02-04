#include <stdio.h>

#include <inttypes.h>

extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z1;
extern float z2;
extern float z3;
extern float z4;
extern float z5;
extern float z11;
extern float z13;
extern float *dataptr;
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

    // First-level sum and diff combinations
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Reduced precision approximation: merge two operations into one via pre-combined constant
    float sum_10_11 = tmp10 + tmp11;
    float dif_10_11 = tmp10 - tmp11;
    dataptr[8 * 0] = sum_10_11;
    dataptr[8 * 4] = dif_10_11;

    // Simplify rotation using single multiplication (approximation)
    z1 = (tmp12 + tmp13) * ((float)0.7071f);
    dataptr[8 * 2] = tmp13 + z1;
    dataptr[8 * 6] = tmp13 - z1;

    // Skip full cascade of temp variables — reduce intermediate steps
    tmp10 = tmp4 + tmp5;
    tmp12 = tmp6 + tmp7;
    z5 = (tmp10 - tmp12) * ((float)0.3827f);
    z2 = tmp10 * ((float)0.5412f) + z5;
    z4 = tmp12 * ((float)1.3066f) + z5;

    // Reuse tmp7 and skip z3/z11 for direct assignment
    dataptr[8 * 7] = tmp7 - tmp11 * ((float)0.7071f) - z4;
    dataptr[8 * 1] = tmp7 + tmp11 * ((float)0.7071f) + z4;
    dataptr[8 * 3] = tmp7 - tmp11 * ((float)0.7071f) - z2;
    dataptr[8 * 5] = tmp7 + tmp11 * ((float)0.7071f) + z2;

    dataptr++;
}
}
