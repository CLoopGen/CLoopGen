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
    float d0 = dataptr[0], d1 = dataptr[1], d2 = dataptr[2], d3 = dataptr[3];
    float d4 = dataptr[4], d5 = dataptr[5], d6 = dataptr[6], d7 = dataptr[7];

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

    dataptr[0] = tmp10 + tmp11;
    dataptr[4] = tmp10 - tmp11;

    z1 = (tmp12 + tmp13) * ((float)0.70710678100000002);
    dataptr[2] = tmp13 + z1;
    dataptr[6] = tmp13 - z1;

    float t10 = tmp4 + tmp5;
    float t11 = tmp5 + tmp6;
    float t12 = tmp6 + tmp7;

    z5 = (t10 - t12) * ((float)0.38268343300000002);
    z2 = ((float)0.54119609999999996) * t10 + z5;
    z4 = ((float)1.3065629649999999) * t12 + z5;
    z3 = t11 * ((float)0.70710678100000002);

    z11 = tmp7 + z3;
    z13 = tmp7 - z3;

    dataptr[5] = z13 + z2;
    dataptr[3] = z13 - z2;
    dataptr[1] = z11 + z4;
    dataptr[7] = z11 - z4;

    dataptr += 8;
}
}
