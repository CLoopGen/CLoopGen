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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    float d0 = dataptr[8 * 0], d7 = dataptr[8 * 7];
    float d1 = dataptr[8 * 1], d6 = dataptr[8 * 6];
    float d2 = dataptr[8 * 2], d5 = dataptr[8 * 5];
    float d3 = dataptr[8 * 3], d4 = dataptr[8 * 4];

    tmp0 = d0 + d7;
    tmp7 = d0 - d7;
    tmp1 = d1 + d6;
    tmp6 = d1 - d6;
    tmp2 = d2 + d5;
    tmp5 = d2 - d5;
    tmp3 = d3 + d4;
    tmp4 = d3 - d4;

    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    float result0 = tmp10 + tmp11;
    float result4 = tmp10 - tmp11;

    z1 = (tmp12 + tmp13) * ((float)0.70710678100000002);
    float result2 = tmp13 + z1;
    float result6 = tmp13 - z1;

    tmp10 = tmp4 + tmp5;
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;

    z5 = (tmp10 - tmp12) * ((float)0.38268343300000002);
    z2 = ((float)0.54119609999999996) * tmp10 + z5;
    z4 = ((float)1.3065629649999999) * tmp12 + z5;
    z3 = tmp11 * ((float)0.70710678100000002);

    z11 = tmp7 + z3;
    z13 = tmp7 - z3;

    float result5 = z13 + z2;
    float result3 = z13 - z2;
    float result1 = z11 + z4;
    float result7 = z11 - z4;

    dataptr[8 * 0] = result0;
    dataptr[8 * 4] = result4;
    dataptr[8 * 2] = result2;
    dataptr[8 * 6] = result6;
    dataptr[8 * 5] = result5;
    dataptr[8 * 3] = result3;
    dataptr[8 * 1] = result1;
    dataptr[8 * 7] = result7;

    dataptr++;
}
}
