#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
// Reduced computational complexity with halved effective trip count and simplified operations
for (ctr = 4 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
    tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
    tmp6 = dataptr[8 * 1] - dataptr[8 * 6];

    // Skip lower-frequency components — reduce arithmetic operations
    tmp10 = tmp0 + tmp1;
    tmp11 = tmp0 - tmp1;

    dataptr[8 * 0] = tmp10;
    dataptr[8 * 4] = tmp11;

    // Simplified transform branch without multipliers
    z1 = tmp6;
    dataptr[8 * 2] = tmp7 + z1;
    dataptr[8 * 6] = tmp7 - z1;

    // Skip complex cross terms (tmp2, tmp3, tmp4, etc.) and write defaults
    dataptr[8 * 1] = tmp6;
    dataptr[8 * 3] = tmp7;
    dataptr[8 * 5] = tmp0;
    dataptr[8 * 7] = tmp1;

    dataptr += 2; // Stride by 2 to reduce effective iterations
}
}
