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
// Consecutive memory access: reinterpret the 8-element strided input as a contiguous block
// Assume dataptr now points to a linearized version of transposed data
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    float *chunk = &dataptr[8 * ctr]; // Access each 8-element row consecutively
    tmp0 = chunk[0] + chunk[7];
    tmp7 = chunk[0] - chunk[7];
    tmp1 = chunk[1] + chunk[6];
    tmp6 = chunk[1] - chunk[6];
    tmp2 = chunk[2] + chunk[5];
    tmp5 = chunk[2] - chunk[5];
    tmp3 = chunk[3] + chunk[4];
    tmp4 = chunk[3] - chunk[4];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    chunk[0] = tmp10 + tmp11;
    chunk[4] = tmp10 - tmp11;
    z1 = (tmp12 + tmp13) * ((float)0.70710678100000002);
    chunk[2] = tmp13 + z1;
    chunk[6] = tmp13 - z1;
    tmp10 = tmp4 + tmp5;
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;
    z5 = (tmp10 - tmp12) * ((float)0.38268343300000002);
    z2 = ((float)0.54119609999999996) * tmp10 + z5;
    z4 = ((float)1.3065629649999999) * tmp12 + z5;
    z3 = tmp11 * ((float)0.70710678100000002);
    z11 = tmp7 + z3;
    z13 = tmp7 - z3;
    chunk[5] = z13 + z2;
    chunk[3] = z13 - z2;
    chunk[1] = z11 + z4;
    chunk[7] = z11 - z4;
}
}
